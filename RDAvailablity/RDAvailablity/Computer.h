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
	string _user;
	Status _status;
	string _mac;
	string _ip;
	bool _isSelected;

public:
	Computer();
	Computer(string name,string ip,string mac);
	~Computer();

	//getters
	string getName();
	string* getUser();
	string getMac();
	string getIP();
	int getStatus();

	//setters
	void setName(string name);
	void setUser(char* user);
	void setStatus(Status newStatus);
	void setMac(string& mac);
	void setIP(string& ip);
	
	//Magic Packets
	int turnOn();

	//extras
	char* deepCopy(string cString);
	void checkUser();
	void remoteDesktop();
	void labView();
	void display();
	string* toString(const char* cString);
	friend ostream& operator<< (  ostream& os,  Computer& comp);
	
	

};




