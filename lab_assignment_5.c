#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	char letter;
	struct node *next;
} node;

int length(node *head)
{
	int count = 0;
	node *tmp = head;
	while (tmp != NULL){
		count++;
		tmp = tmp->next;
	}
	return count;
}

char *toCString(node *head)
{
	int len = length(head);
	node *tmp = head;

	char *str = malloc(len + 1);
	int i = 0;
	while (tmp != NULL)
	{
		str[i++] = tmp->letter;
		tmp = tmp->next;
	}
	str[i] = '\0';
	return str;
}

void insertChar(node **pHead, char c)
{
	node *newNode = (struct node *)malloc(sizeof(node));
	node *tmp = *pHead;

	if(newNode == NULL)
		exit(1);

	/*newNode->letter = c;
	newNode->next = NULL;
	newNode->next = *pHead;
	*pHead = newNode;*/
	newNode->letter = c;
	while(tmp->next != NULL){
		tmp = tmp->next;
	}
	tmp->next = newNode;
}

void deleteList(node **pHead)
{
	node *tmp = *pHead;
	while (tmp != NULL)
	{
		*pHead = tmp->next;
		free(tmp);
		tmp = *pHead;
	}
	*pHead = NULL;
}

int main(void)
{
	int i, strlen, numInputs;
	node *head = NULL;
	char *str;
	char c;
	FILE *inFile = fopen("input.txt", "r");

	fscanf(inFile, " %d\n", &numInputs);

	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strlen);
		for (i = 0; i < strlen; i++)
		{
			fscanf(inFile, " %c", &c);
			insertChar(&head, c);
		}
		str = toCString(head);
		printf("String is: %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}
	fclose(inFile);
}