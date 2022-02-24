#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<conio.h>
using namespace std;
/*
* Node Declaration
*/
struct node_dosen
{
	string nama;
	int kuota;
	int kode;
	int kuota1;
	struct node_dosen *next;
	struct node_dosen *prev;
}*start, *last;

struct node_mahasiswa
{
	string nama , nim , judul , pembimbing1 , pembimbing2;
	int kode_pembimbing1 , kode_pembimbing2;
	struct node_mahasiswa *next1;
	struct node_mahasiswa *prev1;
}*start1, *last1;

int counter = 0;
int counter1 = 0;
int kuota = 5;
int nilai[10];

int o = 1;

const int max = 5;

bool pendeteksi = true;

void testing();
/*
* Class Declaration
*/
class double_clist
{
	public:
	node_dosen *create_dosen(string , int , int);
	node_mahasiswa *create_mahasiswa(string , string , string , int , int);
	void insert_dosen();
	void insert_mahasiswa();
	void display_dosen();
	void display_mahasiswa();
	void update();
	void sort();
	void sort1();
	
	double_clist()
	{
	start = NULL;
	last = NULL;
	start1 = NULL;
	last1 = NULL;
	}
};

void update(int , int);
void delete_pos(int);

/*
* Main: Contains Menu
*/
int main()
{
	int choice;
	nilai[1] = 5;
	nilai[2] = 5;
	nilai[3] = 5;
	double_clist cdl;
	while (1)
	{
		system("cls");
		
		cout << endl;
		cdl.display_dosen();
		cdl.display_mahasiswa();
		
		
		cout << endl;
		
		
		
		
		cout<<"\n-------------------------------"<<endl;
		cout<<"Operations on Doubly Circular linked list"<<endl;
		cout<<"\n-------------------------------"<<endl;
		cout<<"1.Tambah Dosen"<<endl;
		cout<<"2.Tambah Mahasiswa"<<endl;
		cout<<"3.Tampilkan Daftar Berdasarkan Dosen Pembimbing Terbanyak" << endl;
		cout<<"4.Tampilkan Daftar Berdasarkan Dosen Pembimbing Sedikit" << endl;
		cout<<"3.Exit"<<endl;
		cout<<"Enter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
			cdl.insert_dosen();
			
			break;
			case 2:
			cdl.insert_mahasiswa();		
			break;
			case 3:
			cdl.sort1();
			getch();	
			break;
			case 4:
			cdl.sort();	
			break;
			case 5:
			exit(1);
			default:
			cout<<"Wrong choice"<<endl;
			
		}
		
		if (choice != 1 && choice != 3 && choice != 4 && pendeteksi == true)
		{
			testing();
			getch();
		}
		
		
	}
return 0;
}

/*
*MEMORY ALLOCATED FOR NODE DYNAMICALLY
*/
node_dosen* double_clist::create_dosen(string nama , int kuota , int kode)
{
	counter++;
	struct node_dosen *temp;
	temp = new(struct node_dosen);
	temp->nama = nama;
	temp->kuota = kuota;
	temp->kode = kode;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

node_mahasiswa* double_clist::create_mahasiswa(string nama , string nim , string judul , int kode_pembimbing1 , int kode_pembimbing2)
{
	counter1++;
	struct node_mahasiswa *temp;
	temp = new(struct node_mahasiswa);
	temp->nama = nama;
	temp->nim = nim;
	temp->judul = judul;
	temp->kode_pembimbing1 = kode_pembimbing1;
	temp->kode_pembimbing2 = kode_pembimbing2;
	temp->next1 = NULL;
	temp->prev1 = NULL;
	return temp;
}

/*
*INSERTS ELEMNET AT LAST
*/
void double_clist::insert_dosen()
{
	int kode;
	
	string nama;
	cout<<endl<<"Input Nama Dosen : ";
	cin>>nama;
	cout << "Input Kode Dosen : ";
	cin >> kode;
	struct node_dosen *temp;
	temp = create_dosen(nama , kuota , kode);
	if (start == last && start == NULL)
	{
		cout<<"Element inserted in empty list"<<endl;
		start = last = temp;
		start->next = last->next = NULL;
		start->prev = last->prev = NULL;
	}
	else
	{
		last->next = temp;
		temp->prev = last;
		last = temp;
		start->prev = last;
		last->next = start;
	}
	
}

void double_clist::insert_mahasiswa()
{
	int kode_pembimbing1 , kode_pembimbing2;
	string nama , nim , judul;
	
	cout<<endl<<"Input Nama Mahasiswa : ";
	cin>>nama;
	cout<<endl<<"Input NIM Mahasiswa : ";
	cin>>nim;
	cout<<endl<<"Input Judul : ";
	cin>>judul;
	cout << "Input Kode Pembimbing 1 : ";
	cin >> kode_pembimbing1;
	cout << "Input Kode Pembimbing 2 : ";
	cin >> kode_pembimbing2;
	if (kode_pembimbing1 == kode_pembimbing2)
	{
		cout << "kode pembimbing tidak boleh sama!!!";
		pendeteksi = false;
		getch();
		return;
	}
	struct node_mahasiswa *temp;
	temp = create_mahasiswa(nama , nim , judul , kode_pembimbing1 , kode_pembimbing2);
	if (start1 == last1 && start1 == NULL)
	{
		cout<<"Element inserted in empty list"<<endl;
		start1 = last1 = temp;
		start1->next1 = last1->next1 = NULL;
		start1->prev1 = last1->prev1 = NULL;
	}
	else
	{
		last1->next1 = temp;
		temp->prev1 = last1;
		last1 = temp;
		start1->prev1 = last1;
		last1->next1 = start1;
	}
	
}

/*
* Sorting Doubly Circular Link List
*/

/*
* Display Elements of the List
*/
void double_clist::display_dosen()
{
	int i;
	struct node_dosen *s;
	int j;
	
	if (start == last && start == NULL)
	{
		
		cout<<"The List is empty, nothing to display"<<endl;
		return;
	}
	
	s = start;
	
	cout << endl;
	cout << "Daftar Dosen" << endl<<endl;
	cout << "Nama\t\t" << "Kuota Mahasiswa\t\t" << "Kode"<<endl<<endl;
	for (i = 0;i < counter-1;i++)
	{
		
		cout << s->nama << "\t\t\t" << s->kuota << "\t\t" << s->kode << endl;
		s = s->next;
	}
		
		cout << s->nama << "\t\t\t" << s->kuota << "\t\t" << s->kode << endl;
}

void double_clist::display_mahasiswa()
{
	int i , j;
	
	struct node_mahasiswa *s;
	if (start1 == last1 && start1 == NULL)
	{
		
		cout<<"The List is empty, nothing to display"<<endl;
		return;
	}
	s = start1;
	cout << endl;
	cout << "Pembimbing 1\t\t" << "Pembimbing 2\t\t" << "Nama\t\t" << "NIM\t\t" << "Judul"<<endl<<endl;
	for (i = 0;i < counter1-1;i++) 
	{
		cout << s->pembimbing1 << "\t\t\t" << s->pembimbing2 << "\t\t" << s->nama << "\t\t\t" << s->nim << "\t\t\t\t" << s->judul << endl;
		s = s->next1;
		
	}
	
		cout << s->pembimbing1 << "\t\t\t" << s->pembimbing2 << "\t\t" << s->nama << "\t\t\t" << s->nim << "\t\t\t\t" << s->judul << endl;
}

void testing()
{
	struct node_mahasiswa *s;
	struct node_dosen *p;
	int i , j;
	int posisi = 1;
	
	
	
	if (start == last && start == NULL)
	{
		
		cout<<"The List is empty, nothing to display"<<endl;
		return;
	}
	
	p = start;
	for (i = 0;i < counter -1;i++)
	{
		if (start1 == last1 && start1 == NULL)
		{
		
			cout<<"The List is empty, nothing to display"<<endl;
			return;
		} else {
			
			
			s = last1;
			
			if (s->kode_pembimbing1 == p->kode)
			{
				cout << "succes" << endl;
				
				nilai[o]--;
				
				s->pembimbing1 = p->nama;
				update(nilai[o] , posisi);	
			}
			
			if (s->kode_pembimbing2 == p->kode)
			{
				cout << "succes" << endl;
				
				nilai[o]--;
				s->pembimbing2 = p->nama;
				update(nilai[o] , posisi);	
			}
			
		}
		
		if (p->kuota <= 0)
		{
			cout << "full";
			nilai[o] = 0;
			
			p->kuota = 0;
			delete_pos(posisi);
		}
		p = p->next;
		o++;
		posisi++;
	}
		if (s->kode_pembimbing1 == p->kode)
		{
			cout << "succes" << endl;
			
			nilai[o]--;
			s->pembimbing1 = p->nama;
			update(nilai[o] , posisi);
		}
		
		if (s->kode_pembimbing2 == p->kode)
		{
			cout << "succes" << endl;
				
			nilai[o]--;
			s->pembimbing2 = p->nama;
			update(nilai[o] , posisi);	
		}
		
		
		if (p->kuota <= 0)
		{
			nilai[o] = 0;
			
			update(nilai[o] , posisi);
			cout << "full";
			
			delete_pos(posisi);
		}
		
		cout << "success : " << p->kode << endl;
		
		o = 1;
		posisi++;

}





/*
* Update value of a particular node
*/
void update(int a , int b)
{
	int value, i, pos;
	if (start == last && start == NULL)
	{
	cout<<"The List is empty, nothing to update"<<endl;
	return;
	}
	value = a;
	pos = b;
	struct node_dosen *s;
	if (counter < pos)
	{
	cout<<"Position out of range"<<endl;
	return;
	} s= start;
	if (pos == 1)
	{
	s->kuota = value;
	cout<<"Node Updated"<<endl;
	return;
	}
	for (i=0;i < pos - 1;i++)
	{
	s = s->next;
	} 
	s->kuota = value;
	cout<<"Node Updated"<<endl;
}


void double_clist::sort()
{
	struct node_dosen *temp, *s;
	int value, i,value2;
	string value1;
	if (start == last && start == NULL)
	{
		cout<<"The List is empty, nothing to sort"<<endl;
		return;
	} 
	s = start;
	for (i = 0;i < counter;i++)
	{
		temp = s->next;
		while (temp != start)
		{
		if (s->kuota > temp->kuota)
		{
			value = s->kuota;
			s->kuota = temp->kuota;
			temp->kuota = value;
			
			value1 = s->nama;
			s->nama = temp->nama;
			temp->nama = value1;
			
			value2 = s->kode;
			s->kode = temp->kode;
			temp->kode = value2;
		}
		temp = temp->next;
		} 
		s = s->next;
	}
	cout << "succes"<< endl;
}

void double_clist::sort1()
{
	struct node_dosen *temp, *s;
	int value, i,value2;
	string value1;
	if (start == last && start == NULL)
	{
		cout<<"The List is empty, nothing to sort"<<endl;
		return;
	} 
	s = start;
	for (i = 0;i < counter;i++)
	{
		temp = s->next;
		while (temp != start)
		{
		if (s->kuota < temp->kuota)
		{
			value = s->kuota;
			s->kuota = temp->kuota;
			temp->kuota = value;
			
			value1 = s->nama;
			s->nama = temp->nama;
			temp->nama = value1;
			
			value2 = s->kode;
			s->kode = temp->kode;
			temp->kode = value2;
		}
		temp = temp->next;
		} 
		s = s->next;
	}
	cout << "succes"<< endl;
}



void delete_pos(int a)
{
	int pos, i;
	node_mahasiswa *ptr, *s;
	if (start1 == last1 && start1 == NULL)
	{
	cout<<"List is empty, nothing to delete"<<endl;
	return;
	}
	pos = 4;
	if (counter1 < pos)
	{
	cout<<"Position out of range"<<endl;
	return;
	} s= start1;
	if(pos == 1)
	{
		counter1--;
		last1->next1 = s->next1;
		s->next1->prev1 = last1;
		start1 = s->next1;
		free(s);
		cout<<"Element Deleted"<<endl;
	return;
	}
	for (i = 0;i < pos - 1;i++ )
	{
		s = s->next1;
		ptr = s->prev1;
	}
		ptr->next1 = s->next1;
		s->next1->prev1 = ptr;
	if (pos == counter1)
	{
	last1 = ptr;
	}
	counter1--;
	free(s);
	cout<<"Element Deleted"<<endl;
}
