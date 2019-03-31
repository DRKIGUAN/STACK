#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
typedef  struct DStackNode
{
	double data;
	struct StacDkNode *next;
}DStackNode, *LinkDStackPtr;

typedef  struct  LinkDStack{
	LinkDStackPtr top;
	int	count;
}LinkDStack;

typedef  struct CStackNode
{
	char data;
	struct CStackNode *next;
}CStackNode, *LinkCStackPtr;

typedef  struct  LinkCStack{
	LinkCStackPtr top;
	int	count;
}LinkCStack;

typedef enum Status {
    ERROR = 0, SUCCESS = 1
}Status;


#endif
