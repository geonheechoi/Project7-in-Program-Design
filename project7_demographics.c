/*
Project7:
Author :Geonhee Choi
Purpose:  This program read  state (String), 2020 population (int), 2010 population (int), percentage of population whose ages are  
under 5 years old (double), percentage of population whose ages are under 18 years old (double),  
percentage of population whose ages are equal or greater than 65 years old (double), from file and then  write it  by sorted order
*/
#include <stdio.h>
#include <string.h>

#define max_file 100 //maximum of file
#define max_char 150 //maximum of state character

struct state { //struct state

  char state_name[max_char + 1]; //name of state
  int population_2020; //2020 population 
  int population_2010;//2010 population
  double age_5;//percentage of population under 5 years
  double age_18;//percentage of population under 18 years
  double age_65; //percentage of population under 65 years
};

void sort_states(struct state list[], int n);//function definition
int find_smallest(struct state list[], int n);//function definition

int main() {
  struct state name_st[max_char];// state name array
  char input[max_char]; //file input array
  char output[max_char] = "sorted_"; //file output array
  
  printf("Enter the file name:\n"); 

  scanf("%s", input); //scan input

  
  FILE *fp = fopen(input, "r"); //read input FILE
  if (fp == NULL) {
    printf("Error on reading"); //check error
    return 1;
  }

  int i = 0;
  while (!feof(fp) && !ferror(fp) && i < 100) {
    
    fscanf(fp, "%[^,], %d, %d, %lf,%lf,%lf\n", name_st[i].state_name, &name_st[i].population_2020, &name_st[i].population_2010,&name_st[i].age_5, &name_st[i].age_18, &name_st[i].age_65);
    	//scan information from file
    i++;
  }
  
  sort_states(name_st, i); //sort_state function call

  
 
  strcat(output,input);//concatenate about output and input name
  FILE *fp2 = fopen(output, "w"); //writing file
  if (fp2 == NULL) {
    printf("Error on writing"); //check error
    return 1;
  }

  int b;
   
  
  for (b =0;b<i; b++) {
    //print information by sorted order
    fprintf(fp2, "%s, %d, %d, %g, %g %g \n", name_st[b].state_name,name_st[b].population_2020, name_st[b].population_2010,name_st[b].age_5, name_st[b].age_18, name_st[b].age_65);
    
  }
 
  //close file
  fclose(fp);
  fclose(fp2);

  return 0;
}

void sort_states(struct state list[], int n) {
  struct state temp;//temp variable
  int smallest = 100;   //maximum of smallest
  if (n == 1)
    return;
  smallest = find_smallest(list, n);
//call smallest to sort 
  if (smallest < n - 1) {
    temp = list[n - 1];       //swap
    list[n - 1] = list[smallest];
    list[smallest] = temp;
  }

  sort_states(list, n - 1); //call sort function again to make the descending order
}

int find_smallest(struct state list[], int n) { //find smallest to make sorted order
  int i, min_index = 0;//initialize minimum index
  for (i = 1; i < n; i++) {
    if (list[i].age_65 < list[min_index].age_65)  //Your program should include a function that sorts the states by percentage of population whose ages are equal or greater than 65 years old.  
      min_index = i;//match i and minimum
  }
  return min_index; //return to minimum index
}

