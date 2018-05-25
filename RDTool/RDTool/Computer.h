#pragma once
#pragma once
#include <iostream>
#include<string>
using namespace std;


class Computer
{
public:
	enum Status { Available = 0, InUse = 1, Unknown = 2, };
protected:
	string _name;
	string _lab;
	string _college;
	string _user;
	Status _status;
	string _mac;
	string _ip;
	bool _selected;

public:
	Computer();
	Computer(string name, string ip, string mac, string college);
	Computer(const Computer& comp);
	~Computer();

	//getters
	string getName();
	string getUser();
	string getMac();
	string getIP();
	int getStatus();
	bool isSelected();

	//setters
	void setName(string name);
	void setUser(string user);
	void setStatus(Status newStatus);
	void setMac(string& mac);
	void setIP(string& ip);
	void setSelection(bool selection);

	//Four main functions
	int turnOn();
	void remoteDesktop();
	void labView();
	void writeCommand(string command);

	//extras
	char* deepCopy(string cString);
	void checkUser();
	void display();
	string getLab();
	string getCollege();
	string runCommand(string cmd,bool checkUser);

	bool operator <(Computer& comp);
	bool operator >(Computer& comp);
	bool operator >=(Computer& comp);
	bool operator <=(Computer& comp);
	bool operator==(Computer& comp);
	void operator=(const Computer& comp);


	friend ostream& operator<< (ostream& os, Computer& comp);



};




