#include "Computer.h"
#include <stdio.h>
#include <stdlib.h>
#include<fstream>
#include<iomanip>
#include<Windows.h>

Computer::Computer()
{
	_name = "\0";
	_user = string();
	_ip = "\0";
	_mac = "\0";
	_status = Computer::Unknown;
	_selected = false;
}

Computer::Computer(string name, string ip, string mac, string college)
{
	_name = name;
	_user = string();
	_ip = ip;
	_mac = mac;
	_college = college;
	size_t found = _name.find_last_of('-');
	_lab = _name.substr(0, found);
	_status = Computer::Unknown;
	_selected = false;
}

Computer::Computer(const Computer & comp)
{
	_name = comp._name;
	_user = comp._user;
	_status = comp._status;
	_mac = comp._mac;
	_ip = comp._ip;
	_selected = comp._selected;

}

Computer::~Computer()
{
	//TODO: Finish writing this

}

void Computer::setName(string name)
{
	_name = name;

}

void Computer::setUser(string user)
{

	_user = user;
}


int Computer::getStatus()
{
	return _status;
}

bool Computer::isSelected()
{
	return _selected;
}

string Computer::getName()
{
	return _name;
}

string Computer::getUser()
{
	return _user;
}

string Computer::getMac()
{
	return _mac;
}

string Computer::getIP()
{
	return _ip;
}

char* Computer::deepCopy(string cString)
{
	int arrayLength = 0;

	for (arrayLength; cString[arrayLength] != '\0'; arrayLength++)
	{

	}
	arrayLength++;
	char* out = new char[arrayLength];
	for (int i = 0; i < arrayLength; i++)
	{
		if (i == arrayLength - 1)
		{
			out[i] = '\0';
		}
		else
		{
			out[i] = cString[i];
		}
	}
	return out;
}

string Computer::runCommand(string cmd)
{
	int size = cmd.size();
	string command = "";
	command += cmd.substr(0, 4);
	//copy(cmd.begin(), cmd.end(), command);
	command += " /node:\"" + _name;
	command += "\" ";
	command += cmd.substr(5, size);
	TCHAR *param = new TCHAR[command.size() + 1];
	param[command.size()] = 0;

	copy(command.begin(), command.end(), param);

	BOOL bSuccess = false;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	string result = "Computer in Error State!";

	ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));

	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);

	bSuccess = CreateProcess(NULL,
		param,
		NULL,
		NULL,
		TRUE,
		0,
		NULL,
		NULL,
		&si,
		&pi);

	auto trial = WaitForSingleObject(pi.hProcess, 1000);

	if (!bSuccess)
	{
		cout << "Process failed" << endl;
		cout << command << endl;
		ExitProcess(1);
	}
	else
	{
		if (trial == WAIT_OBJECT_0)
		{
			char buffer[128];
			result = "";
			const char* charCommand = command.c_str();
			//TODO: Stop running the commmand twice. Find a way to get the out put from hStdOutput

			//cout << "get into exec" << endl;

			FILE* pipe = _popen(charCommand, "r");
			if (!pipe) throw runtime_error("_popen() failed!");
			try
			{
				while (!feof(pipe))
				{
					if (fgets(buffer, 128, pipe) != NULL)
					{
						result += buffer;
					}
				}
			}
			catch (...) {
				_pclose(pipe);
				throw;
			}
			_pclose(pipe);
		}
		return result;

	}
}

void Computer::checkUser()
{
	//Runs the command to find a user on a PC
	string cmd = "wmic computersystem get username";		//Runs the command to find a user on a PC

	string result = runCommand(cmd);
	int newLine = string::npos;
	newLine = result.find('\\');

	
	string user;
	//result.find("SOONER") != string::npos
	if (result == "Computer in Error State!")
	{
		setStatus(Status(Unknown));
	}
	else if (newLine == string::npos)
	{
		cout << "This is available" << endl;
		setStatus(Status(Available));
	}
	//else if (result.find('E') != string::npos)
	
	else
	{
		setStatus(Status(InUse));
		//user = result.substr(result.find('R') + 2, 8);
		
		user = result.substr(newLine + 1, 10);
		setUser(user);
	}
}

void Computer::remoteDesktop()
{
	//If the staus is known, then connect using the name
	if (_status != 2)
	{
		string command = "mstsc.exe /v:" + _name;
		FILE *f = _popen(command.c_str(), "r");
	}
	//The stauts is unknown then try to connect using the IP
	else
	{
		string command = "mstsc.exe /v:" + _ip;
		FILE *f = _popen(command.c_str(), "r");
	}
}

void Computer::labView()
{
	string command = "\"C:\\Program Files (x86)\\Microsoft Configuration Manager\\AdminConsole\\bin\\i386\\CmRcViewer.exe\" " + _name;
	FILE *f = _popen(command.c_str(), "r");
	return;
}

void Computer::writeCommand(string command)
{
	FILE* f = _popen(command.c_str(), "r");
}

void Computer::display()
{
	cout << (*this) << endl;
}

string Computer::getLab()
{
	return _lab;
}

string Computer::getCollege()
{
	return _college;
}

bool Computer::operator<(Computer & comp)
{
	return (_name < comp._name);
}

bool Computer::operator>(Computer & comp)
{
	return (_name > comp._name);
}

bool Computer::operator>=(Computer & comp)
{
	if (comp._name > _name)
	{
		return true;
	}
	else if (comp._name == _name)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Computer::operator<=(Computer & comp)
{
	if (comp._name < _name)
	{
		return true;
	}
	else if (comp._name == _name)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Computer::operator==(Computer & comp)
{
	if (comp._name == _name)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Computer::operator=(const Computer & comp)
{
	_name = comp._name;
	_user = comp._user;
	_status = comp._status;
	_mac = comp._mac;
	_ip = comp._ip;
	_selected = comp._selected;
}

void Computer::setStatus(Status newStatus)
{
	_status = newStatus;
	return;
}

void Computer::setMac(string& mac)
{
	_mac = mac;
	return;
}

void Computer::setIP(string& ip)
{
	_ip = ip;
	return;
}

void Computer::setSelection(bool selection)
{
	_selected = selection;
}

int Computer::turnOn()
{
	string command = "start powershell.exe -noexit -file \"\\\\norfile\\ls-repo\\Repository\\Learning Spaces\\Sysadmin Tools\\Magic Packet\\wol2.ps1\" " + _mac + "-Verb RunAs";
	FILE *f = _popen(command.c_str(), "r");
	return 0;
}

ostream & operator<<(ostream & os, Computer & comp)
{
	int compStatus = comp.getStatus();
	string foo = comp.getUser();
	os << "Computer: " << comp.getName() << "\nIP: " << comp.getIP() << "\nMac: " << comp.getMac() << "\n" << comp.getLab() << "\n" << comp.getCollege() << "\n";
	if (compStatus == 1)
	{
		os << "In use by: " << (foo) << endl;
	}
	else if (compStatus == 2)
	{
		os << "Unavailable" << endl;
	}
	else
	{
		os << "Available" << endl;
	}
	return os;
}
