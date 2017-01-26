#include <iostream>
#include <ctime>
#include <cstdlib> 
#include <cstring>
#include <fstream>
#include <iomanip> 
using namespace std;

const int bombnum[6] = {0,20,40,60,80,100};
const int maxn = 200;
const bool cheat = 00;
const int maxlife = 9;

int ans,correct,nowcount,totalcount,useless,flag,life;
int ci;
bool bomb[205];
string recordname[7];
int record[35];

fstream file;

void Line();
void Initial(int I);
void build(int J);
void Record(int K,int N);
void Changerecord(int L,int M,int O);

int main()
{
	srand((unsigned) time (NULL));
	int left,right;

	printf("\t�׷��K�X ver1.6  �E�R������(�״_�w��BUG�B�]��{���X�u��)\n\n");
	printf("(�q�Ʀr��X�K�X�A����쬵�u�|���A�l��1���R�A��ͩR�k�s�A�N��F)\n\n"); 
	printf("��J�r���βŸ��|�ɭP�C���Y��A�Ъ`�N�C\n\n");
	printf("�s�@ : �x�n�@����T��-Snorlax\n");
	Line();
	printf("�K�X�d��G%d ~ %d\n",0,maxn);
	Line();	
	system("pause");
	printf("\n�C���}�l\n");
	Line();
	
	for(int ci = 1;ci <= 5;ci ++)	{
		Initial(ci);
		left = 1;
		right = 200;
		while(ans != correct)	{
			nowcount ++;
			totalcount ++;
			if(cheat == 1)	{
				printf("(%d)",correct);	
			}	
			printf("�п�J�q�����Ʀr�A��e�q�����ơG %d ���A�`�q�����ơG %d ���C\n",nowcount,totalcount);
			scanf("%d",&ans);
			if(ans > right || ans < left)	{
				printf("\n\n�A����J���X�k ! �Э��s��J\n");
			}
			else if(bomb[ans] == 1 && life == 1)	{
				Line();
				printf("\n\n�A�b�� %d ������ %d �^�X�򤤤F���u�C\n",ci,nowcount);
				printf("�A���ͩR�w�g�k�s�C\n");
				printf("�C�������C\n");
				printf("�����K�X��: %d �C\n",correct);
				Record(0,ci);
				flag = 0;
				printf("\n���w�ڰ����p�C���� ? �Q�g�X�o�˪��F��A�w��[�J��T��!!\n");
				break;
			}
			else if(bomb[ans] == 1)	{
				Line();
				life --;
				printf("\n\n�A�b�� %d ������ %d �^�X�򤤤F���u�C\n",ci,nowcount);
				printf("�A���ͩR���C�F 1 �I�A��e�ͩR�G %d / %d\n",life,maxlife);
				printf("\n��e�d��:%d ~ %d\n",left,right);
			}
		    else if(ans > correct)	{
				printf("\n�A��J���Ʀr�j��K�X�C\n");
				right = ans - 1; 
				printf("\n��e�d��:%d ~ %d\n",left,right);
			}
			else if(ans < correct)	{
				printf("\n�A��J���Ʀr�p��K�X�C\n");
				left = ans + 1;
				printf("\n��e�d��:%d ~ %d\n",left,right);
			}
			else if(ci == 5)	{
				printf("\n\n���ץ��T�I�A�q�L�F�C���I\n�A�`�@�q�������ƬO%d ���A�A�Ѿl���ͩR�O %d / %d �C\n",totalcount,life,maxlife);
				Record(1,ci); 
				printf("\n���w�ڰ����p�C���� ? �Q�g�X�o�˪��F��A�w��[�J��T��!!\n");
				break;
			}
			else	{
				printf("\n���ץ��T!�i�J�U�@��!\n");
				Line();
				system("pause");
			}
			Line();
			}
			if(flag == 0)	{
				break;
			}
	}
	return 0;
}	

void Line(){
	printf("--------------------------------\n");
}

void Initial(int I)	{
	ans = 0;
	nowcount = 0;
	flag = 1;
	if(I == 1)	{
		totalcount = 0;
		life = maxlife;
	} 
	memset(bomb,0,sizeof(bomb));
	printf("\n\n\t���d %d / 5 , �������d�� %d �����u�C\n\n",I,bombnum[I]);
	Line();
	printf("���ͱK�X�P���u��......\n");
	build(I);
	printf("�K�X�P���u�w���ͧ����I\n");
	Line();
}

void build(int J)	{
	correct = rand()% maxn + 1;
	bomb[correct] = 1;
	for(int j = 1;j <= bombnum[J];j ++)	{
		useless = rand()% maxn + 1;
		if(bomb[useless] == 0)	{
			bomb[useless] = 1;
		}
		else	{
			j --;
		}
	}
	bomb[correct] = 0;
}

void Record(int K,int N)	{
	file.open("record.txt",ios::in);
	for(int i = 1;i <= 25;i ++)	{
		if(i <= 5)	{
			file >> recordname[i];	
		}
		else	{
			file >> record[i - 5];
		}
	}
	file.close();
	Line();
	for(int i = 1;i <= 5;i ++)	{
		cout << "�� " << record[i] << " �W: " << left << setw(14) << recordname[i] << "  (" ;
		if(record[i + 5] == 0)	{
			cout << "��� " << record[i + 10] << " ������ " << record[i + 15] << " �B���`�C)\n"; 
		}
		else	{
			cout << "��� " << record[i + 10] << " �B�q�L�C���A�Ѿl " << record[i + 15] << " �I�ͩR�C)\n"; 
		}
	} 
	
	for(int i = 1;i <= 5;i ++)	{		//�i�H�ƶi���W�� 
		if(K == 1)	{					//���� 
			if(record[i + 5] == 0 || (record[i + 5] == 1 && record[i + 10] > N ) || (record[i + 5] == 1 && record[i + 10] == N && life >= record[i + 15]))	{
				for(int j = 4;j >= i;j --)	{
					recordname[j + 1] = recordname[j];
				}
				for(int j = 9;j >= i + 5;j --)	{
					record[j + 1] = record[j];
				}
				for(int j = 14;j >= i + 10;j --)	{
					record[j + 1] = record[j];
				}
				for(int j = 19;j >= i + 15;j --)	{
					record[j + 1] = record[j];
				}
				Changerecord(i,K,N); 
				break;
			} 
		} 
		else	{
			if((record[i + 5] == 0 && N > record[i + 10]) || (record[i + 5] == 0 && N == record[i + 10] && totalcount >= record[i + 15] ))	{
				for(int j = 4;j >= i;j --)	{
					recordname[j + 1] = recordname[j];
				}
				for(int j = 9;j >= i + 5;j --)	{
					record[j + 1] = record[j];
				}
				for(int j = 14;j >= i + 10;j --)	{
					record[j + 1] = record[j];
				}
				for(int j = 19;j >= i + 15;j --)	{
					record[j + 1] = record[j];
				}
				Changerecord(i,K,N); 
				break;
			}
		}
	}
}
void Changerecord(int L,int M,int O){
	record[L + 5] = M;
	string name;
	Line();
	printf("���ߡI�A�����Z���H�n�W�]��A�п�J�A���ʺ�(�ФŹL���Τ���)�G\n");
	cin >> name;
	recordname[L] = name;
	
	if(M == 1)	{
		record[L + 10] = totalcount;
		record[L + 15] = life;
	}
	else	{
		record[L + 10] = O;
		record[L + 15] = totalcount;
	}
	Line();
	
	printf("�s���]�欰�G\n");
	for(int i = 1;i <= 5;i ++)	{
		cout << "�� " << record[i] << " �W: " << left << setw(14) << recordname[i] << "  (" ;
		if(record[i + 5] == 0)	{
			cout << "��� " << record[i + 10] << " ������ " << record[i + 15] << " �B���`�C)\n"; 
		}
		else	{
			cout << "��� " << record[i + 10] << " �B�q�L�C���A�Ѿl " << record[i + 15] << " �I�ͩR�C)\n"; 
		}
	} 
	Line();
	printf("�]���x�s��......\n�]���x�s�����C\n");
	file.close();
	file.open("record.txt",ios::out);
	for(int i = 1;i <= 25;i ++)	{
		if(i <= 5)	{
			file << recordname[i] << endl;	
		}
		else	{
			file << record[i - 5] << ' ';
		}
	} 
}
