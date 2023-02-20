#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;
template<typename t>

void PrintEnvironment(t** array, int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

void floodfill(int** array,int x, int y, int rows, int cols)
{
    
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));

    while(!q.empty()){
        
        pair<int,int> p = q.front();
        int val = array[p.first][p.second];
    
    if(p.first + 1 < rows && array[p.first + 1][p.second] == 0)
    {
        array[p.first + 1][p.second] = val + 1;
        q.push(make_pair(p.first + 1,p.second));
    }

    if (p.first - 1 >= 0 && array[p.first - 1][p.second] == 0)
    {
        array[p.first - 1][p.second] = val + 1;
        q.push(make_pair(p.first - 1,p.second));
    }
    
    if (p.second + 1 < cols && array[p.first][p.second + 1] == 0)
    {
        array[p.first][p.second + 1] = val + 1;
        q.push(make_pair(p.first,p.second+1));
    }

    if (p.second - 1 >= 0 && array[p.first][p.second - 1] == 0)
    {
        array[p.first][p.second - 1] = val + 1;
        q.push(make_pair(p.first,p.second-1));
    }

    if(p.first + 1 < rows && p.second + 1 < cols && array[p.first + 1][p.second + 1] == 0)
    {
        array[p.first + 1][p.second + 1] = val + 1;
        q.push(make_pair(p.first + 1,p.second+1));
    }

    if(p.first + 1 < rows && p.second - 1 >= 0 && array[p.first + 1][p.second - 1] == 0)
    {
        array[p.first + 1][p.second - 1] = val + 1;
        q.push(make_pair(p.first + 1,p.second-1));
    }

    if(p.first - 1 >= 0 && p.second + 1 < cols && array[p.first - 1][p.second + 1] == 0)
    {
        array[p.first - 1][p.second + 1] = val + 1;
        q.push(make_pair(p.first - 1,p.second+1));
    }

    if(p.first - 1 >= 0 && p.second - 1 >= 0 && array[p.first - 1][p.second - 1] == 0)
    {
        array[p.first - 1][p.second - 1] = val + 1;
        q.push(make_pair(p.first - 1,p.second - 1));
    }
    q.pop();
    }
}


void blockGenerator(int** array, int rows, int cols, int random)
{
    for(int i = 0; i < (random * rows * cols) / 100; i++)
    {
        int x = rand() % rows ;
        int y = rand() % cols;
        array[x][y] = -1;
    }
}



void charArray(int** array, int rows, int cols,char** path)
{
    
        for (int i = 0; i < rows; i++)
        {
        for(int j = 0; j < cols; j++)
        {
            if(array[i][j] == -1)
            {
              path[i][j]  =  (char)178;
            }
            else if(array[i][j] == 1)
            {
              path[i][j]  =  '$';
            }
            else
            {
                path[i][j] = ' ';
            }
        }
    }
}

void greedytravel(int **array, int startX, int startY, int rows, int cols, char **path)
{

    queue<pair<int, int>> q;
    pair <int, int> x;
    int current = array[startX][startY];
    q.push(make_pair(startX, startY));
    while (!q.empty() && current != 1)
    {
        pair<int, int> p = q.front();
        int val = array[p.first][p.second];
        if (p.first + 1 < rows && array[p.first + 1][p.second] >0 && array[p.first + 1][p.second] <= current)
        {
                current = array[p.first + 1][p.second];
                x = make_pair(p.first + 1, p.second);
        }

        if (p.first - 1 >= 0 && array[p.first - 1][p.second] >0 && array[p.first - 1][p.second] <= current)
        {
                current = array[p.first - 1][p.second];
                x = make_pair(p.first - 1, p.second);
        }

        if (p.second + 1 < cols && array[p.first][p.second + 1] >0 && array[p.first][p.second + 1] <= current)
        {
                current = array[p.first][p.second + 1];
                x = make_pair(p.first, p.second + 1);
        }

        if (p.second - 1 >= 0 && array[p.first][p.second - 1] >0 && array[p.first][p.second - 1] <= current)
        {
                current = array[p.first][p.second - 1];
                x = make_pair(p.first, p.second - 1);
        }

        if (p.first + 1 < rows && p.second + 1 < cols && array[p.first + 1][p.second + 1] >0 && array[p.first + 1][p.second + 1] <= current)
        {
                current = array[p.first + 1][p.second + 1];
                x = make_pair(p.first + 1, p.second + 1);
        }

        if (p.first + 1 < rows && p.second - 1 >= 0 && array[p.first + 1][p.second - 1] >0 && array[p.first + 1][p.second - 1] <= current)
        {
                current = array[p.first + 1][p.second - 1];
                x = make_pair(p.first + 1, p.second - 1);
        }

        if (p.first - 1 >= 0 && p.second + 1 < cols && array[p.first - 1][p.second + 1] >0 && array[p.first - 1][p.second + 1] <= current)
        {
                current = array[p.first - 1][p.second + 1];
                x = make_pair(p.first - 1, p.second + 1);
        }

        if (p.first - 1 >= 0 && p.second - 1 >= 0 && array[p.first - 1][p.second - 1] >0 && array[p.first - 1][p.second - 1] <= current)
        {
                current = array[p.first - 1][p.second - 1];
                x = make_pair(p.first - 1, p.second - 1);
        }
        q.pop();
        q.push(x);
        path[x.first][x.second] = '*';
    }
    if(current != 1){
        cout<<"Path not found"<<endl;
    }
}

int main(){
    

    int rows,randomness = -1, cols,**space, flag =1;
    int goalX, goalY, startX, startY;
    
    
    
    cout<<"Welcome to the WaveFront Pather!"<<endl;
    cout<<"\nPlease enter the details to generate the grid: "<<endl;
    cout<<"Enter the number of rows: (atleast 10)";
    cin>>rows;
    cout << "Enter the number of columns: (atleast 10)";
    cin>>cols;
    space = new int*[rows];
    for (int i = 0; i < rows;i++)
        space[i] = new int[cols];
    do{
        cout<<"Enter the randomness of the grid (0-100): ";
        cin >> randomness;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout<<"Please enter a valid number!"<<endl;
        }
        else if(randomness >= 35){
            char choice;
            cout<<"Randomness above 35% might create poor results, continue?(y/n)"<<endl;
            cin>>choice;
            if(choice == 'y' || choice == 'Y'){
                flag = 0;
            }
        }
        else
            flag = 0;
        
    }
    while(flag);

    for(int i=0;i<rows;i++){

        for(int j=0;j<cols;j++){
            space[i][j]=0;
        }
    }
    blockGenerator(space,rows,cols,randomness);
    PrintEnvironment(space, rows, cols);
    flag = 1;
    do{
        cout<<"Please enter the Goal Position X: ";
        cin>>goalX;
        cout<<"Please enter the Goal Position Y: ";
        cin>>goalY;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout<<"Please enter a valid number!"<<endl;
        }
        else if(space[goalX][goalY] == -1){
            cout<<"There is a block present in that position. Re-enter again!"<<endl;
        }
        else{
            flag = 0;
        }
    }
    while(flag);
    
    space[goalX][goalY]=1; // the goal state
    
    floodfill(space, goalX, goalY, rows, cols);
    
    char **path = new char*[rows];
    
    for (int i = 0; i < rows;i++)
        path[i] = new char[cols];

    PrintEnvironment(space, rows, cols);
    charArray(space, rows, cols, path);
    flag  = 1;
    do{
        cout<<"Please enter the Start Position X: ";
        cin>>startX;
        cout<<"Please enter the Start Position Y: ";
        cin>>startY;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout<<"Please enter a valid number!"<<endl;
        }
        else if(space[startX][startY] == -1 ){
            cout<<"There is a block/goal present in that position. Re-enter again!"<<endl;
        }
        else{
            flag = 0;
        }
    }while(flag);
    path[startX][startY] = '@';
    greedytravel(space, startX, startY,rows, cols , path);
    path[goalX][goalY] = '$';
    PrintEnvironment(path, rows, cols);
    return 0;
}

