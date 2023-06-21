#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CursorBased.h"

Student newStudent(int studID, String studName, char sex, String program){
	Student s;
	
	s.studID = studID;
	strcpy(s.studName, studName);
	s.sex = sex;
	strcpy(s.program, program);

	return s;
}

VirtualHeap newVirtualHeap(){
	VirtualHeap vh;
	int i;
	for(i=0;i<MAX;++i){
		vh.elems[i].elem = newStudent(0,"", ' ', "");
		vh.elems[i].next = i-1;
	}
	vh.avail = MAX-1;
	
	return vh;
}
int allocSpace(VirtualHeap *vh){
	int retVal = vh->avail;
	
	if(retVal!=-1){
		vh->avail = vh->elems[vh->avail].next;
		return retVal;
	}
}
void insertFront(VirtualHeap *vh, List *list, Student s){
	List temp = allocSpace(vh);
	
	if(temp!=-1){
		vh->elems[temp].next = *list;
		*list = temp;
		vh->elems[temp].elem = s;
	}
}

void displayList(VirtualHeap vh, List list){
	int i;
	printf("DISPLAY LIST:\n");
	printf("%5s | %30s | %10s | %s\n", "ID", "NAME", "PROGRAM", "SEX");
	for(i=list;i<MAX;++i){
		if(vh.elems[i].elem.sex != ' '){
			
			printf("%5d | %30s | %10s | %c\n", vh.elems[i].elem.studID, vh.elems[i].elem.studName, vh.elems[i].elem.program, vh.elems[i].elem.sex);
		}
	}
	printf("\n");
}

void visualizeSpace(VirtualHeap vh){
	int i;
	printf("%5s | %30s | %s\n", "INDEX", "ELEMENTS", "NEXT");
	
	printf("---------------------------------------------\n");
	for(i=0;i<MAX;++i){
		printf("%5d | ", i);
		if(vh.elems[i].elem.studID == 0){
			printf("%30s | ","EMPTY");
		}
		else{
			printf("%4d - %23s | ", vh.elems[i].elem.studID, vh.elems[i].elem.studName);
		}
		printf("%d\n", vh.elems[i].next);
	}
	printf("---------------------------------------------\n");
	printf("AVAILABLE: %d\n\n", vh.avail);
}

Student removeStudent(VirtualHeap *vh, List *list, String keyword){
	int i;
	List *trav, temp;
	Student s;
	
	for(trav=list;*trav!=1 && strcmp(vh->elems[*trav].elem.studName, keyword)!=0; trav= &vh->elems[*trav].next){}
	
	if(*trav!=1){
		temp = *trav;
		s = vh->elems[temp].elem;
		*trav = vh->elems[temp].next;
		deallocSpace(vh, temp);
	}
	return s;

}

void deallocSpace(VirtualHeap *vh, int index){
	if(index != -1 && index < MAX){
		vh->elems[index].next = vh->avail;
		vh->elems[index].elem = newStudent(0, "", ' ', "");
		vh->avail = index;
	}
}

