#include "Computer.h"
#include <stdio.h>
#include <stdlib.h>

Computer::Computer()
{
	_name = "\0";
	_user = string();
	_ip = "\0";
	_mac = "\0";
	_status = Computer::Unknown;
	_selected = false;
}

Computer::Computer(string name,string ip,string mac,string college)
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

void Computer::setUser(char* user)
{
	
	_user = string(user);
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

string* Computer::getUser()
{
	return &_user;
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
	for (int i = 0;i < arrayLength; i++)
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

void Computer::checkUser()
{
	//Runs the command to find a user on a PC
	string command = "wmic /node:\"" + _name + "\" computersystem get username 2>&1";		//Runs the command to find a user on a PC
	char* number = new char[20];
	//Opens Powershell
	FILE *f = _popen(command.c_str(), "r");
	int count = 0;
	int index = 0;
	char* out = new char[16];
	
	//While there is stuff to get, get it
	while (fgets(number, 100, f) != NULL)
	{
		fgets(number, 20, f);
		for (count; number[count] != '\0'; count++)
		{
			count++;
		}
		count++;
		//Check to see if there is a user, by looking for the S in SOONER\4x4
		if (number[0] == 'S' )
		{
			int j = 0;
			for (int i = 7; i < 15; i++)
			{
				out[j] = number[i];
				j++;
			}
			out[j] = '\0';
			setStatus(Status(InUse));
			setUser(out);
		}
		//If computer is off by looking for the E in ERROR
		else if (number[0] == 'E')
		{
			setStatus(Status(Unknown));
		}
		//Computer is not in use
		else
		{
			setStatus(Status(Available));
		}
		index++;
		if (index == 1)
		{
			break;
		}
	}
	_pclose(f);
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
	string command = "start powershell.exe -noexit -file \"\\\\norfile\\ls-repo\\Repository\\Learning Spaces\\Sysadmin Tools\\Magic Packet\\wol2.ps1\" " + _mac + "-Verb RunAs" ;
	FILE *f = _popen(command.c_str(), "r");
	return 0;
}

ostream & operator<<( ostream & os,   Computer & comp)
{
	int compStatus = comp.getStatus();
	string* foo = comp.getUser();
	os << "Computer: " << comp.getName() << "\nIP: " << comp.getIP() << "\nMac: " << comp.getMac() << "\n" << comp.getLab() << "\n"<< comp.getCollege()<<"\n";
	if (compStatus == 1) 
	{
		os << "In use by: " << (*foo) << endl;
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
