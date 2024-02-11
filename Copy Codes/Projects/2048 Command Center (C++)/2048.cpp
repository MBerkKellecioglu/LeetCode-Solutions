#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void Random(int (*matrix)[4]);
void Print(int (*matrix)[4]);
void Shuffle(int (*matrix)[4], int, int);
int Collison(int (*matrix)[4], int , int, int, int);
int EndGame(int (*matrix)[4]);

int main(){
	
	int matrix[4][4], dir, flag;
	
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4 ; j++){
			
			matrix[i][j] = 0;
		}
	}
	
	while(EndGame){
		Random(matrix);
		Print(matrix);
		cin >> dir >> flag;
		Shuffle(matrix, dir, flag);
		Print(matrix);
		cout << endl;
	}
	
}

void Random(int (*matrix)[4]){
	
	int empty[32], r, arr[2] = {2,4}, k = 0;
	
	srand(time(0));
	
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4 ; j++){
			
			if(matrix[i][j] == 0){
				empty[k] = i;
				k++;
				empty[k] = j;
				k++;
			}
		}
	}
	
	r = rand() % k;
	
	if(r % 2 == 0){
		matrix[empty[r]][empty[r + 1]] = arr[rand() % 2];
	}
	else{
		matrix[empty[r - 1]][empty[r]] = arr[rand() % 2];
	}
}


void Print(int (*matrix)[4]){
	
	for(int i = 0; i < 4; i++){
		cout << endl;
		for(int j = 0; j < 4 ; j++){
			
			cout << matrix[i][j] << " " ;
		}
	}
}

void Shuffle(int (*matrix)[4], int dir, int flag){
	
	int temp, var1 = 3, var2 = 0, var3 = -1, var4 = 4, i, j, k ,*ptr1 = &i, *ptr2 = &j, *ptr3 = &i, *ptr4 = &k, *ptr5 = &i, *ptr6 = &j, dir1 = 0, dir2 = dir, temp1, temp2, *tptr;
	
	if(dir == -1){
		var1 = 0;
		var2 = 4;
		var3 = 4;
	}
	
	if(flag == 1){
		dir1 = dir;
		dir2 = 0;
	}
	
	for(i = 0; i < 4; i++){
		if(flag == 1){
		ptr1 = &j;
		ptr2 = &i;
		ptr3 = &k;
		ptr4 = &i;
		}    																				
		for(j = var1; j != var2; j = j - dir){															
			for(k = j - dir; k != var3; k = k - dir){
				if(matrix[*ptr3][*ptr4] != 0){
					if(matrix[*ptr1][*ptr2] == matrix[*ptr3][*ptr4]){
						matrix[*ptr1][*ptr2] += matrix[*ptr3][*ptr4];
						matrix[*ptr3][*ptr4] = 0;
						break;
					}
					else{
						continue;
					}
				}
				else{
					continue;
				}
			}
		}
	}
	
	for(i = 0; i < 4; i++){
		for(j = var1; j != var3; j = j - dir){
			temp1 = *ptr5;
			temp2 = *ptr6;
			tptr = &temp2;
			if(flag == 1){
				temp1 = *ptr6;
				temp2 = *ptr5;
				tptr = &temp1;
			}
			if(matrix[temp1][temp2] != 0){
				while(Collison(matrix, temp1, temp2, dir, flag)){
					if(*tptr == var1){
						break;
					}
					else{
						matrix[temp1 + dir1][temp2 + dir2] = matrix[temp1][temp2];
						matrix[temp1][temp2] = 0;
						if(flag == 1){
							temp1 = temp1 + dir;
						}
						else{
							temp2 = temp2 + dir;
						}
						
					}
						
				}	
			}
			else{
				continue;
					
			}
		}
	}
		
}

int Collison(int (*matrix)[4], int ind1, int ind2, int dir, int flag){
	
	if(flag != 1){
		if(matrix[ind1][ind2 + dir] == 0){
			return true;
		}
		else{
			return false;
		}	
	}
	else{
		if(matrix[ind1 + dir][ind2] == 0){
			return true;
		}
		else{
			return false;
		}
	}
		
}

int EndGame(int (*matrix)[4]){
	
	int count = 1;
	
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4 ; j++){
			if(matrix[i][j] != 0){
				count++;
			}
		}
	}
	
	if(count == 16){
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				if(matrix[i][j] == matrix[i][j + 1] || matrix[i][j] == matrix[i + 1][j] || matrix[i][3] == matrix[i + 1][3]){
					return false;
				}
				else{
					return true;
				}
			}
		}
	}
	
}


