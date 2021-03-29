#include <iostream>
#include "List.h"

int main() {
  List* xorList = new List();
  char* command = (char*)malloc(sizeof(char)*500);
  int numInput = 0;

  while (scanf(" %s", command) > 0) {
    if (strcmp(command, "ADD_BEG") == 0) {
      scanf("%d",&numInput);
      xorList->AddAtStart(numInput);
    }
    else if(strcmp(command,"ADD_END") == 0)  {
      scanf("%d",&numInput);
      xorList->AddAtEnd(numInput);
    }
    else if (strcmp(command,"ADD_ACT") == 0) {
      scanf("%d",&numInput);
      xorList->AddAtPrev(numInput);
    }
    else if (strcmp(command, "DEL_VAL") == 0) {
      scanf("%d",&numInput);
      xorList->RemoveValues(numInput);
    }
    else {
      if (strcmp(command, "ACTUAL") == 0)
        xorList->Curr();
      else if (strcmp(command, "NEXT") == 0)
        xorList->Next();
      else if (strcmp(command, "PREV") == 0)
        xorList->Prev();
      else if (strcmp(command, "DEL_BEG") == 0)
        xorList->RemoveFromStart();
      else if (strcmp(command, "DEL_END") == 0)
        xorList->RemoveFromEnd();
      else if (strcmp(command, "DEL_ACT") == 0)
        xorList->RemoveCurr();
      else if (strcmp(command, "PRINT_FORWARD") == 0)
        xorList->TraverseForward();
      else if (strcmp(command, "PRINT_BACKWARD") == 0)
        xorList->TraverseBackward();
    }
  }
  free(command);
  return 0;
}
