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
    if(i > 0 && i < 4999){
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
                if(str[j] == 'C' && j > i+2){
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
                if(str[j] == 'M' && j > i+3){
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
void sortArabic(LinkedList l)
{
    bool swapped = true;
    DoubleLinkNode* cur = l.getHead();

    cout << l.getTail()->roman << endl <<l.getTail()->arabic << endl<<endl;
    while(swapped){
        swapped = false;
        cur = l.getHead();
        while(cur->next != nullptr){
            if(cur->arabic > cur->next->arabic){
                if(!cur->next->next){
                    cout<<cur->arabic << endl;
                    cout<< cur->roman << endl;
                    DoubleLinkNode*hold = cur->next;
                    cur->next = nullptr;
                    hold->next = cur;
                    cur->prev->next = hold;
                    //cur->next->prev = hold->prev;
                    hold->prev = cur->prev;
                    cur->prev = hold;
                    swapped = true;
                    break;
                }
                else if(cur->prev){
                    cout<<cur->arabic << endl;
                    cout<< cur->roman << endl;
                    DoubleLinkNode*hold = cur->next;
                    cur->next = cur->next->next;
                    hold->next = cur;
                    cur->prev->next = hold;
                    cur->next->prev = cur;
                    hold->prev = cur->prev;
                    cur->prev = hold;
                    swapped = true;
                }
                else{
                    DoubleLinkNode*hold = cur->next;
                    cur->next = cur->next->next;
                    hold->next = cur;
                    cur->next->setPrev(cur);
                    l.setHead(hold);
                    swapped = true;

                }
            }
            cur = cur->next;
        }
    }
}

void sortRoman(LinkedList l)
{
    bool swapped = true;
    DoubleLinkNode* cur = l.getHead();

    //cout << l.getTail()->roman << endl <<l.getTail()->arabic << endl<<endl;
    while(swapped){
        swapped = false;
        cur = l.getHead();
        while(cur->next != nullptr){
            if(cur->roman > cur->next->roman){
                if(!cur->next->next){
                    cout<<cur->arabic << endl;
                    cout<< cur->roman << endl;
                    DoubleLinkNode*hold = cur->next;
                    cur->next = nullptr;
                    hold->next = cur;
                    cur->prev->next = hold;
                    //cur->next->prev = hold->prev;
                    hold->prev = cur->prev;
                    cur->prev = hold;
                    swapped = true;
                    break;
                }
                else if(cur->prev){
                    cout<<cur->arabic << endl;
                    cout<< cur->roman << endl;
                    DoubleLinkNode*hold = cur->next;
                    cur->next = cur->next->next;
                    hold->next = cur;
                    cur->prev->next = hold;
                    cur->next->prev = cur;
                    hold->prev = cur->prev;
                    cur->prev = hold;
                    swapped = true;
                }
                else{
                    DoubleLinkNode*hold = cur->next;
                    cur->next = cur->next->next;
                    hold->next = cur;
                    cur->next->setPrev(cur);
                    l.setHead(hold);
                    swapped = true;

                }
            }
            cur = cur->next;
        }
    }
}


/*
void sortRoman(LinkedList l)
{
    bool swapped = false;
    DoubleLinkNode* cur = l.getHead();


    while(!swapped){
        swapped = false;
        while(cur->next){
            if(cur->roman > cur->next->roman){
                DoubleLinkNode*hold = cur->next;
                cur->next = cur->next->next;
                hold->next = cur;
                cur->prev->next = hold;
                cur->next->prev = cur;
                hold->prev = cur->prev;
                cur->prev = hold;
                swapped = true;
            }
            cur = cur->next;
        }
    }
}
*/
//Binary search on list uses recursion
bool binSearch(DoubleLinkNode*head,int length,int target){
    DoubleLinkNode*cur = head;
    int count = 0;
    //Goes to middle of list
    while(cur->next && count < (length / 2)){
        count++;
        cur = cur->next;
    }
            //If only 1 value remains it is checked, base case
            if(length == 1){
                if(cur->arabic == target){
                    return true;
                }
                return false;
            }

            //If value is found true is returned and it stops searching
            if(cur->arabic == target){
                return true;
            }
            //If the middle value is greater than what is being searched for, the search is called recursively on the first half of the list
            else if(cur->arabic > target){
                return binSearch(head, length / 2, target );
            }
            //If the middle value is less than what is being searched for, the search is called recursively on the second half of the list
            else if(cur->arabic < target){
                return binSearch(cur,(length / 2) + 1,target);
            }
}


int main()
{
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

            //llist += new DoubleLinkNode(line.substr(0,16),convertToArabic(line.substr(0,16)));
            //EnQueue(head,line.substr(0,16), convertToArabic(line.substr(0,16)));
        }

    }

    sortArabic(llist);


        //output to file
    file.close();
    //Opens file in output mode
    ofstream fileO(fileName);
    DoubleLinkNode*ptr = llist.getHead();
    //Prints each node from list on a line into the file
    while(ptr != nullptr){
        fileO << ptr->roman;
        for(int i = 0; i + ptr->roman.length() < 20;i++){
            fileO << " ";
        }
        fileO << ptr->arabic << endl;
        ptr = ptr->next;
    }
    return 0;
}
