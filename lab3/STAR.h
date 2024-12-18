#ifndef STAR_H
#define STAR_H

int GetInt(int *a); 
void ShowMas(int **a, int *b);
void DeleteMas(int **PPtr, int d, int *b);
void CreateMas(int **PPmas, int g);
void IndTask(int **PPmas,int **Parr, int *size_of_mas);
void Insert(int **PPmas, int *size_of_mas);
void Remove(int **PPmas, int *size_of_mas );
void Replace(int **PPmas, int *size_of_mas);

#endif
