#indef TREE_H_
#define TREE_H_
#define <stdbool.h>
#define MAXSIZE 20 

typedef struct item{
	char petname[MAXSIZE];
	char petkind[MAXSIZE];
}Item;

typedef struct tnode{
	Item item;
	struct Tronde *lift;
	struct Tronde *right;
}Tnode;

typedef struct tree{
	Tronde * root;
	int size;
}Tree;

typedef struct pair{
	Tnode *parents;
	Tnode *child;
}Pair;

//¶¨Òåº¯Êý

void Initialize(Tree * ptree);

bool TreeIsFull(const Tree* ptree);

bool TreeIsEmpty(const Tree* ptree);

int TreeItemCount(const Tree*ptree);

bool AddItem(Item item,Tree* ptree);

bool InTree(Item *item,Tree* ptree);

bool DeleteItem(Item item,Tree* ptree);

bool Traverse(const Tree*ptree,void (*pfun)(Item item));

bool DeleteAll(Tree * ptree);

#endif

