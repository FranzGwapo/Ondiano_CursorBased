#include <stdio.h>
#include <stdlib.h>
#include "CursorBased.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	VirtualHeap myHeap = newVirtualHeap();
	String stud;
	List myList = -1;
	List anotherList = -1;
//	visualizeSpace(myHeap);
	
	insertFront(&myHeap, &myList, newStudent(101,"Jonathan", 'm', "BS IT"));
	insertFront(&myHeap, &myList, newStudent(105,"Sebastian", 'm', "BS CS"));
	insertFront(&myHeap, &myList, newStudent(109,"Micka", 'f', "BS CS"));
	insertFront(&myHeap, &myList, newStudent(102,"Pwans", 'm', "BS IT"));
	
	insertFront(&myHeap, &anotherList, newStudent(100,"Christine", 'f', "BS Math"));
	
	visualizeSpace(myHeap);
	
	displayList(myHeap, myList);
	
	printf("Who do you want to remove? ");
	scanf("%s", &stud);
	
	Student s;
	s = removeStudent(&myHeap, &myList, stud);
	printf("Removed %s in the List\n", s.studName);
	displayList(myHeap, myList);
	return 0;
}
