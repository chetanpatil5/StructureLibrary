#include<stdio.h>
#include<string.h>

struct Library
{
	int accno;
	char title[30];
  	char author[30];
  	float price;
  	int flag;
};

void AddBookInfo(struct Library [],int );
void Display(struct Library [],int );
void SimilarAuthor(struct Library [],int );
void TitleBook(struct Library [],int );
void CountBooksInLib(struct Library [],int );
void SortBooksByAccession(struct Library [],int );

int main()
{
	struct Library books[5]={
      {1,"WingsofFire","APJ",200,1},
      {2,"A","B",300,0},
      {3,"IgnitedMinds","APJ",280,0},
      {4,"C","D",80,1},
      {5,"E","F",100,0}
      };

      
      int ch;
      while(1)
      {
      	printf("\n\n1: Add book information");
		printf("\n2: Display book information");
		printf("\n3: List all books of given author");
		printf("\n4: List the title of specified book");
		printf("\n5: List the count of books in the library");
		printf("\n6: List the books in order of accesion number");
		

		printf("\nEnter Your Choice : ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:AddBookInfo(books,5);
					break;
			case 2:Display(books,5);
					break;
			case 3:SimilarAuthor(books,5);
					break;
			case 4:TitleBook(books,5);
					break;
			case 5:CountBooksInLib(books,5);
					break;
			case 6:SortBooksByAccession(books,5);
					break;
		}

      }
	return 0;
}

void AddBookInfo(struct Library b[],int n)
{
	int acc;
	int flag1=0;
	printf("\nEnter the Accession no of the book : ");
	scanf("%d",&acc);
	printf("Modify the information as follows :");
	
		for(int i=0;i<n;i++)
		{
			if(acc==b[i].accno)
			{

			printf("\nAccession No :");
			scanf("%d",&b[i].accno);

			printf("\nEnter Title :");
			scanf("%s",b[i].title);

			printf("\nEnter Author :");
			scanf("%s",b[i].author);

			printf("\nEnter Price :");
			scanf("%f",&b[i].price);

			printf("\nEnter flag :");
			scanf("%d",&b[i].flag);

			flag1=1;
			}
		
		}
		if(flag1==0)
		{
			printf("\nNo Record Found");
		}
		else
		{
			printf("\nAdded Successfully\n");
		}


}

void Display(struct Library b[],int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("\n\nAccession Number : %d",b[i].accno);
		printf("\nTitle of book : %s",b[i].title);
		printf("\nAuthor : %s",b[i].author);
		printf("\nPrice : %f",b[i].price);
		printf("\nBook issued : %d",b[i].flag);

	}
}

void SimilarAuthor(struct Library b[],int n)
{
	char auth[20];
	int flag1=0;
	int c;
	printf("\nEnter the name of the author");
	scanf("%s",auth);

	for (int i = 0; i < n; ++i)
	{
		c=strcmp(auth,b[i].author);
		if(c==0)
		{
			printf("\nTitle of book : %s",b[i].title);
			flag1=1;	
		}
		
	}
	if(flag1==0)
	{
		printf("\nNo Author Found.");
	}
}

void TitleBook(struct Library b[],int n)
{
	char title[20];
	int flag1=0;
	int c;
	printf("\nEnter the title of the book :");
	scanf("%s",title);

	for (int i = 0; i < n; ++i)
	{
		c=strcmp(title,b[i].title);
		if(c==0)
		{
			printf("\nBook Found:");
			printf("\nTitle of book : %s",b[i].title);
			flag1=1;
			break;	
		}
		
	}
	if(flag1==0)
	{
		printf("\nNo Book with title %s Found.",title);
	}
}
void CountBooksInLib(struct Library b[],int n)
{
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(b[i].flag==0)
		{
			cnt++;
		}
	}
	printf("\nCount of Books Present in the Library are : %d",cnt);
}
void SortBooksByAccession(struct Library b[],int n)
{
	struct Library temp;
	for(int i=0;i<n;i++) 
	{
		for(int j=i+1;j<n-1;j++)
		{

		if(b[i].accno>b[j].accno) 
		{
			temp=b[i];
			b[i]=b[j];
			b[j]=temp;
		}
		}
	}
	printf("\nSorted Successfully");
	//Display(b,5);
	for (int i = 0; i < n; ++i)
	{
		printf("\n\nAccession Number : %d",b[i].accno);
		printf("\nTitle of book : %s",b[i].title);
		printf("\nAuthor : %s",b[i].author);
		printf("\nPrice : %f",b[i].price);
		printf("\nBook issued : %d",b[i].flag);

	}
}