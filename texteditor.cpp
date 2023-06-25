#include <iostream>
#include <string.h>
using namespace std;
class TextEditor{
public:
string currenttext;
int cursor;
TextEditor(){ currenttext="^"; cursor=0;
		cout<<currenttext<<endl;}
void addText(string text){
	string lefttemp=currenttext.substr(0,cursor);
	string righttemp=currenttext.substr(cursor, currenttext.size()-cursor);
	lefttemp=lefttemp+text;
	currenttext=lefttemp+righttemp;
	cursor=cursor+text.size();
	cout<<currenttext<<endl;
}
void deleteText(int k){
	if (k>cursor) {currenttext=currenttext.substr(cursor, currenttext.size()-cursor);
			cursor=0;}
	else { string templeft=currenttext.substr(0, cursor-k);
		string tempright=currenttext.substr(cursor, currenttext.size()-cursor);
		currenttext=templeft+tempright;
		cursor=cursor-k;
		}
	cout<<currenttext<<endl;
}
void backspace(){
	deleteText(1);
}
int findCursor(){ return cursor;}
void cursorLeft(int k){
	if(k>cursor) { string tempmid=currenttext.substr(0, cursor);
		string tempright=currenttext.substr(cursor+1, currenttext.size()-cursor-1);
		currenttext="^"+tempmid;
		currenttext=currenttext+tempright;
		cursor=0;}
	else{
	string templeft=currenttext.substr(0, cursor-k);
	string tempmid=currenttext.substr(templeft.size(), k);
	string tempright=currenttext.substr(cursor+1, currenttext.size()-cursor-1);
	currenttext=templeft+"^";
	currenttext=currenttext+tempmid;
	currenttext=currenttext+tempright;
	cursor=cursor-k;
	}
	cout<<currenttext<<endl;
}
void cursorRight(int k){
	int len=currenttext.size()-1;
	int n;
	if (k+cursor>len) n= len-cursor;
	else n=k;
		string templeft=currenttext.substr(0, cursor);
		string tempmid=currenttext.substr(cursor+1, n);
		string tempright=currenttext.substr(cursor+n+1, currenttext.size()-cursor-1-n);
		currenttext=templeft+tempmid;
		currenttext=currenttext+"^";
		currenttext=currenttext+tempright;
		cursor=cursor+n;
	cout<<currenttext<<endl;
}
string fullText(){
	string templeft=currenttext.substr(0, cursor);
	string tempright=currenttext.substr(cursor+1, currenttext.size()-cursor-1);
	string newtext=templeft+tempright;
	return newtext;
}
string showText(int k){
	string text=currenttext.substr(cursor+1, k);
	return text;
}
};
int main()
{
	string text;
	int k;
	int option;
	TextEditor obj= TextEditor();
	cout<<"1.Add text\n2.Delete text\n3.Backspace\n4.Find Cursor\n5.Move cursor left\n6.Move cursor right\n7.Print full text\n8.Show text\n9. Exit" <<endl;
	int flag=1;
	while (flag){
		cout<<"Enter the option"<<endl;
		cin>>option;
		switch(option){
			case 1: cout<<"Enter the text"<<endl;
				cin >> text;
				obj.addText(text);
				break;
			case 2: cout<<"Enter number of characters to delete"<<endl;
				cin>>k;
				obj.deleteText(k);
				break;
			case 3:obj.backspace();
				break;
			case 4:cout<< "cursor at position: "<<obj.findCursor() <<endl;
				break;
			case 5:cout<<"Number of positions to move:"<<endl;
				cin>>k;
				obj.cursorLeft(k);
				break;
			case 6:cout<<"Number of positions to move:"<<endl;
				cin>>k;
				obj.cursorRight(k);
				break;
			case 7:cout<<obj.fullText()<<endl;
				break;
			case 8:cout<<"Number of characters to show: "<<endl;
				cin>>k;
				obj.showText(k);
				break;
			case 9:flag=0;
		}
	}
	return 0;		
		
}
