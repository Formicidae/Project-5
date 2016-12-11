//DELETE ANY NODE
//Edward Bates emb160030 1337.002 project 5
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>

#include "DoubleLinkNode.h"
#include "LinkedList.h"

using namespace std;

int convertToArabic(string rom) {
	int sum = 0;
	//Checks every character in the roman numeral
	//Looks for each value in the tens place and for 4s and 9s checks after C, X or I
	for (int i = 0; i < rom.length(); i++)
	{
		if (rom[i] == 'M')
			sum += 1000;
		else if (rom[i] == 'D')
			sum += 500;
		else if (rom[i] == 'C' && (rom[i + 1] == 'M' || rom[i + 1] == 'D'))
			sum -= 100;
		else if (rom[i] == 'C')
			sum += 100;
		else if (rom[i] == 'L')
			sum += 50;
		else if (rom[i] == 'X' && (rom[i + 1] == 'L' || rom[i + 1] == 'C'))
			sum -= 10;
		else if (rom[i] == 'X')
			sum += 10;
		else if (rom[i] == 'V')
			sum += 5;
		else if (rom[i] == 'I' && (rom[i + 1] == 'V' || rom[i + 1] == 'X'))
			sum -= 1;
		else if (rom[i] == 'I')
			sum += 1;
	}
	return sum;

}

string convertToRoman(int num) {
    //Gets the number in the thousands, hundreds, tens and ones place
	string output = "";
	int thou = num / 1000;
	int hun = (num % 1000) / 100;
	int tens = ((num % 1000) % 100) / 10;
	int ones = (((num % 1000) % 100) % 10);

	//looks first for places that are less than 4
	//then checks for 4 and 5 nad adds those values
	//then adds any values greater than 5

	if (thou > 0 && thou <= 4)
	{
		for (int i = 0; i < thou; i++)
		{
			output += "M";
		}
	}
	if (hun > 0 && hun < 4)
	{
		for (int i = 0; i < hun; i++)
		{
			output += "C";
		}
	}
	else if (hun == 4) {
		output += "CD";
	}
	else if (hun == 5) {
		output += "D";
	}
	else if (hun > 5 && hun < 9)
	{
	    output += "D";
		for (int i = 5; i < hun; i++)
		{
			output += "C";
		}
	}
	else if (hun == 9)
		output += "CM";

	if (tens > 0 && tens < 4) {
		for (int i = 0; i < tens; i++)
		{
			output += "X";
		}
	}
	else if (tens == 4)
	{
		output += "XL";
	}
	else if (tens == 5)
	{
		output += "L";
	}
	else if (tens > 5 && tens < 9)
	{
	    output += "L";
		for (int i = 5; i < tens; i++)
		{
			output += "X";
		}
	}
	else if(tens == 9){
		output += "XC";
	}
	if (ones > 0 && ones < 4) {
		for (int i = 0; i < ones; i++) {
			output += "I";
		}
	}
	else if (ones == 4)
	{
		output += "IV";
	}
	else if (ones == 5) {
		output += "V";
	}
	else if (ones > 5 && ones < 9) {
        output += "V";
		for (int i = 5; i < ones; i++)
		{
			output += "I";
		}
	}
	else if(ones == 9){
		output += "IX";
	}
	return output;
}

bool decInvalid(string str){
    //Converts input from string to int
    stringstream myStream(str);
    int i;
    myStream >> i;
    //Checks if input is in the right range, also checks the conversion worked
    if(i > 0 && i < 5000){
        return false;
    }
    return true;
}

bool romInvalid(string str){
    //Checks if string contains an characters other than the ROman ones
    for(int i = 0;i < str.length();i++){
        if(str[i] != ' ' && str[i] != 'I' && str[i] != 'V' && str[i] != 'X' && str[i] != 'L' && str[i] != 'C' && str[i] != 'D' && str[i] != 'M'){
            return true;
        }
    }
    //Checks if I is followed by any characters it shouldn't be
    for(int i = 0;i < str.length();i++){
        if(str[i] == 'I'){
            for(int j = i;j < str.length();j++){
                if(str[j] != 'I' && str[j] != 'V' && str[j] != 'X' && str[j] != ' '){
                    return true;
                }
                if(str[j] == 'V' && j > i+1){
                    return true;
                }
                if(str[j] == 'X' && j > i+1){
                    return true;
                }

            }
        }
    }

    //Checks if V is followed by any characters it shouldn't be
    for(int i = 0;i < str.length();i++){
        if(str[i] == 'V'){
            for(int j = i+1;j < str.length();j++){
                if(str[j] != 'I' && str[j] != ' '){
                    return true;
                }
            }
        }
    }

    //Checks if X is followed by any characters it shouldn't be

    for(int i = 0;i < str.length();i++){
        if(str[i] == 'X'){
            for(int j = i+1;j < str.length();j++){
                if(str[j] != 'I' && str[j] != 'V' && str[j] != 'L' && str[j] != 'C' && str[j] != 'X' && str[j] != ' ')
                    return true;

            if(str[j] == 'L' && j > i+1){
                return true;
            }
            if(str[j] == 'C' && j > i+1){
                return true;
            }
            if(str[j] == 'X' && j > i+2){
                    return true;
            }
        }
        }
    }

    //Checks if L is followed by any characters it shouldn't be
    for(int i = 0;i < str.length();i++){
        if(str[i] == 'L'){
            for(int j = i+1;j < str.length();j++){
                if(str[j] != 'I' && str[j] != 'V' && str[j] != 'X' && str[j] != ' ')
                    return true;
            }
        }
    }

    //Checks if C is followed by any characters it shouldn't be
    for(int i = 0;i < str.length();i++){
        if(str[i] == 'C'){
            for(int j = i+1;j < str.length();j++){
                if(str[j] != 'I' && str[j] != 'V' && str[j] != 'X' && str[j] != 'C' && str[j] != 'D' && str[j] != 'L' && str[j] != 'M' && str[j] != ' ')
                    return true;
                if(str[j] == 'D' && j > i+1){
                    return true;
                }
                if(str[j] == 'M' && j > i+1){
                    return true;
                }
                if(str[j] == 'C' && j > i+6){
                    return true;
                }
            }
        }
    }

    //Checks if D is followed by any characters it shouldn't be
    for(int i = 0;i < str.length();i++){
        if(str[i] == 'D'){
            for(int j = i+1;j < str.length();j++){
                if(str[j] != 'I' && str[j] != 'V' && str[j] != 'X'&& str[j] != 'C'&& str[j] != 'L' && str[j] != ' ')
                    return true;
            }
        }
    }

    //Checks if M is followed by any characters it shouldn't be
    for(int i = 0;i < str.length();i++){
        if(str[i] == 'M'){
            for(int j = i+1;j < str.length();j++){
                if(str[j] != 'I' && str[j] != 'V' && str[j] != 'X'&& str[j] != 'C'&& str[j] != 'L'&& str[j] != 'D' && str[j] != 'M' && str[j] != ' ')
                    return true;
                if(str[j] == 'M' && j > i+8){
                    return true;
                }
            }
        }
    }
    char rom[20];
    strcpy(rom,str.c_str());
    if(strstr(rom,"IIII"))
        return true;
    if(strstr(rom,"IVI"))
        return true;
    if(strstr(rom,"IXI"))
        return true;
    if(strstr(rom,"XXXX"))
        return true;
    if(strstr(rom,"XLX"))
        return true;
    if(strstr(rom,"XCX"))
        return true;
    if(strstr(rom,"CCCC"))
        return true;
    if(strstr(rom,"CDC"))
        return true;
    if(strstr(rom,"CMC"))
        return true;
    if(strstr(rom,"MMMMM"))
        return true;

    return false;
}

//Sort Arabic
void sortArabic(LinkedList& l)
{
    //Checks if there is only 1 element
    if(l.getHead() == l.getTail()){
        return;
    }
    bool swapped = true;
    DoubleLinkNode* cur = l.getHead();

    //Sorts list until nothing gets moved
    while(swapped){
        swapped = false;
        cur = l.getHead();
        //Loops though list looking for things to swap
        while(cur->getNext() != nullptr){
            if(cur->getArabic() > cur->getNext()->getArabic()){
                //Special case for Tail
                if(cur->getNext()->getNext() == nullptr){
                    DoubleLinkNode*hold = cur->getNext();
                    cur->setNext(nullptr);
                    hold->setNext(cur);
                    cur->getPrev()->setNext(hold);
                    //cur->next->prev = hold->prev;
                    hold->setPrev(cur->getPrev());
                    cur->setPrev(hold);
                    l.setTail(cur);
                    swapped = true;
                    break;
                }
                //Main case for all the elements in th middle
                else if(cur != l.getHead()){
                    DoubleLinkNode*hold = cur->getNext();
                    cur->setNext(cur->getNext()->getNext());
                    hold->setNext(cur);
                    cur->getPrev()->setNext(hold);
                    cur->getNext()->setPrev(cur);
                    hold->setPrev(cur->getPrev());
                    cur->setPrev(hold);
                    swapped = true;
                }
                //Special case for Head of list
                else{
                    DoubleLinkNode*hold = cur->getNext();
                    cur->setNext(cur->getNext()->getNext());
                    hold->setNext(cur);
                    cur->getNext()->setPrev(cur);
                    l.setHead(hold);
                    cur->setPrev(hold);
                    swapped = true;
                }
            }
            cur = cur->getNext();
        }
    }
}

//Same as Arabic sort but alphabetically by Roman
void sortRoman(LinkedList & l)
{
    bool swapped = true;
    DoubleLinkNode* cur = l.getHead();
    while(swapped){
        swapped = false;
        cur = l.getHead();
        while(cur->getNext() != nullptr){
            if(cur->getRoman() > cur->getNext()->getRoman()){
                if(cur->getNext()->getNext() == nullptr){
                    DoubleLinkNode*hold = cur->getNext();
                    cur->setNext(nullptr);
                    hold->setNext(cur);
                    cur->getPrev()->setNext(hold);
                    hold->setPrev(cur->getPrev());
                    cur->setPrev(hold);
                    l.setTail(cur);
                    swapped = true;
                    break;
                }
                else if(cur->getPrev()){
                    DoubleLinkNode*hold = cur->getNext();
                    cur->setNext(cur->getNext()->getNext());
                    hold->setNext(cur);
                    cur->getPrev()->setNext(hold);
                    cur->getNext()->setPrev(cur);
                    hold->setPrev(cur->getPrev());
                    cur->setPrev(hold);
                    swapped = true;
                }
                else{
                    DoubleLinkNode*hold = cur->getNext();
                    cur->setNext(cur->getNext()->getNext());
                    hold->setNext(cur);
                    cur->getNext()->setPrev(cur);
                    l.setHead(hold);
                    cur->setPrev(hold);
                    swapped = true;
                }
            }
            cur = cur->getNext();
        }
    }
}

//Binary search on list uses recursion
bool binSearch(DoubleLinkNode*head,int length,int target)
{
    DoubleLinkNode*cur = head;
    int count = 0;
    //Goes to middle of list
    while(cur->getNext() && count < (length / 2))
    {
        count++;
        cur = (cur->getNext());
    }
    //If only 1 value remains it is checked, base case
    if(length == 1)
    {
        if(cur->getArabic() == target)
        {
            return true;
        }
        return false;
    }
    //If value is found true is returned and it stops searching
    if(cur->getArabic() == target)
    {
        return true;
    }
    //If the middle value is greater than what is being searched for, the search is called recursively on the first half of the list
    else if(cur->getArabic() > target)
    {
        return binSearch(head, length / 2, target );
    }
    //If the middle value is less than what is being searched for, the search is called recursively on the second half of the list
    else if(cur->getArabic() < target)
    {
        return binSearch(cur,(length / 2) + 1,target);
    }
}

int main()
{
    //Opens file in read mode
    string fileName = "numbers.txt";
    ifstream file(fileName);
    string line;
    int i;
    LinkedList llist;

    //Reads each line of file
    while(file.good())
    {
        getline(file,line);
        //If the line is arabic
        if(line.substr(0,1) == " ")
        {
            //If it's invalid, it skips the line
            if(decInvalid(line.substr(16,20))){
                continue;
            }

            //converts to roman and adds it to the linked list
            stringstream myStream(line.substr(16,20));
            myStream >> i;
            DoubleLinkNode * newNode = new DoubleLinkNode;
            newNode->setArabic(i);
            newNode->setRoman(convertToRoman(i));

            llist += newNode;

            //EnQueue(head,convertToRoman(i), i);
        }
        else{
            //checks if its a roman numeral, if not its skipped
            if(romInvalid(line.substr(0,16))){
                continue;
            }
            //If it is a roman numeral it is converted to arabic and added to the list
            DoubleLinkNode * newNode = new DoubleLinkNode;
            newNode->setArabic(convertToArabic(line.substr(0,16)));
            newNode->setRoman(line.substr(0,16));

            llist += newNode;
        }

    }

    //Interface
    int choice = 0;
    string target;
    bool stage1 = true;
    while(stage1){
        cout << "\n\t1\tSearch" << endl;
        cout << "\t2\tAdd" << endl;
        cout << "\t3\tDelete First" << endl;
        cout << "\t4\tDelete last" << endl;
        cout << "\t5\tDelete any node" << endl;
        cout << "\t6\tExit\n" << endl;
        choice = 0;

        string input;

        //Checks if input is valid and converts it to int
        cin >> input;
        if(input.length() > 1){
            choice = 7;
        }
        else{
            stringstream i(input);
            i >> choice;
        }

        switch(choice){
            case 1:{
                sortArabic(llist);
                cout << "What would you like to search for" << endl;
                cin >> target;
                //Checks if there is only 1 element
                if(llist.getHead() == llist.getTail()){
                    stringstream myStream(target);
                    int i;
                    myStream >> i;
                    if(i == llist.getHead()->getArabic()){
                        cout << endl << target << " Was found";
                        break;
                    }
                    else{
                        cout << endl << target << " Wasn't found";
                        break;
                    }
                }

                stringstream myStream(target);
                int p;
                myStream >> p;
                if(llist.getTail()->getArabic() < p){
                    cout << endl << target << " Wasn't found";
                    break;
                }

                //If its a roman its converted to arbic for searching
                if(!romInvalid(target)){
                    cout << "";

                    i = convertToArabic(target);

                    DoubleLinkNode*countP = llist.getHead();
                    //Counts the length of the list
                    int count = 1;
                    while(countP->getNext()){
                        count++;
                        countP = (countP->getNext());
                    }
                    //Runs binary search
                    if(binSearch(llist.getHead(),count,i)){
                        cout << endl << target << " Was found";
                    }
                    else{
                        cout << endl << target << " Wasn't found";
                    }
                    break;
                }
                //If the target is in arabic
                if(!decInvalid(target)){
                    cout << "";

                    //Convert into an int for the search
                    stringstream myStream(target);
                    int i;
                    myStream >> i;

                    DoubleLinkNode*countP = llist.getHead();
                    //Counts the length of the list
                    int count = 1;
                    while(countP != nullptr){
                        count++;
                        countP = countP->getNext();
                    }
                    //Runs binary search
                    if(binSearch(llist.getHead(),count,i)){
                        cout << endl << i << " Was found";
                    }
                    else{
                        cout << endl << i << " Wasn't found";
                    }
                }
                else{
                    cout << "Invalid Input" << endl;
                }
                break;
            }
            case 2:{
                //adds a new node using the overloaded >> of BaseNode
                cout << "What would you like to add?";
                DoubleLinkNode*add = new DoubleLinkNode();
                cin >> add;
                //Adds node with overloaded +=
                llist += add;
                if(add->getRoman() != ""){
                    add->setArabic(convertToArabic(add->getRoman()));
                }
                else{
                    add->setRoman(convertToRoman(add->getArabic()));
                }
                sortArabic(llist);
                break;
                }
            case 3:{
                //Delete from begining of list
                sortArabic(llist);
                --llist;
                break;
            }
            case 4:{
                //Delete from end of list
                sortArabic(llist);
                llist--;
                break;
            }
            case 5:{
                //Extra credit delete anywhere
                cout << "What do you want to delete?";
                cin >> target;
                int t;
                bool found = false;
                cout << "";
                //Figures out what type it is and converts to int
                if(!romInvalid(target)){
                    t = convertToArabic(target);
                }
                else if(!decInvalid(target)){
                    //Convert into an int
                    stringstream myStream(target);
                    myStream >>t;
                }

                DoubleLinkNode*cur = llist.getHead();
                //Loops though to find node to delete
                while(cur != nullptr){
                    //If the list only has one element it makes it a null node
                    if(cur->getArabic() == t){
                        if(llist.getHead() == llist.getTail()){
                            llist.getHead()->setRoman("");
                            llist.getHead()->setArabic(0);
                            found = true;
                            break;
                        }

                        //If the desired value is the head it uses prefix
                        if(cur == llist.getHead()){
                            cout << target << "\nHas been deleted\n";
                            --llist;
                            found = true;
                            break;
                        }
                        //If the desired value is the Tail it uses postfix
                        if(cur == llist.getTail()){
                            cout << target << "\nHas been deleted\n";
                            llist--;
                            found = true;
                            break;
                        }
                        cur->getPrev()->setNext(cur->getNext());
                        cur->getNext()->setPrev(cur->getPrev());
                        delete cur;

                        cout << target << "\nHas been deleted\n";
                        found = true;
                        break;
                    }
                    cur = cur->getNext();
                }
                if(!found){
                    cout << "Value wasn't found\n";
                }
                break;
            }

            case 6:{
                stage1 = false;
                break;
            }

        }
    }

    sortArabic(llist);

    file.close();
    //Opens file in output mode
    ofstream fileO(fileName);
    DoubleLinkNode*ptr = llist.getHead();
    //Prints each node from list on a line into the file

    llist.print(fileO,llist.getHead());

    llist.deleteL(llist.getHead());

    return 0;
}
