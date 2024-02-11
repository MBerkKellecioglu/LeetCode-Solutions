#include"stack.cpp"
#include<vector>
#include<algorithm>
#include<iostream>
#include<time.h>

class maze{

private:
    vector<vector<cell>> _maze;
    int row;
    int col;
    int cell_count;

    void initMaze(){
        for(int x = 0; x < row; x++){
            vector<cell> tmp;
            for(int y = 0; y < col; y++){
                cell new_cell(x,y);
                tmp.push_back(new_cell);
            }
            _maze.push_back(tmp);
        }
    }

    void generatePerfectMaze(){
        stack<cell*> cache;

        cell *curr_cell = &_maze[0][0];

        curr_cell->Checked();

        cache.push(curr_cell);

        while(!cache.empty()){
            curr_cell = cache.top();

            int x = curr_cell->getX();
            int y = curr_cell->getY();

            int wall = selectRandomWall(x, y);

            if(wall == 0){
                cache.pop();
            }
            else if(wall == 1){
                curr_cell->breakRightWall();

                _maze[x][y + 1].breakLeftWall();
                _maze[x][y + 1].Checked();

                curr_cell = &_maze[x][y + 1];

                cache.push(curr_cell);
            }
            else if(wall == 2){
                curr_cell->breakLeftWall();

                _maze[x][y - 1].breakRightWall();
                _maze[x][y - 1].Checked();

                curr_cell = &_maze[x][y - 1];

                cache.push(curr_cell);
            }
            else if(wall == 3){
                curr_cell->breakDownWall();

                _maze[x + 1][y].breakUpWall();
                _maze[x + 1][y].Checked();

                curr_cell = &_maze[x + 1][y];

                cache.push(curr_cell);
            }
            else if(wall == 4){
                curr_cell->breakUpWall();

                _maze[x - 1][y].breakDownWall();
                _maze[x - 1][y].Checked();

                curr_cell = &_maze[x - 1][y];

                cache.push(curr_cell);
            }
        }
    }

public:

    maze(int M, int N){
        row = M;
        col = N;
        cell_count = M*N;
        initMaze();
        generatePerfectMaze();
    }

    void Control(){
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                cout << _maze[i][j].getX() << " " << _maze[i][j].getY() << " " << _maze[i][j].getRightWall() << "R"<< " " << _maze[i][j].getLeftWall() << "L" << " " << _maze[i][j].getUpWall() << "U"<< " " << _maze[i][j].getDownWall() << "D";
                cout << endl; 
            }
            cout << endl;
        }
    }

    int selectRandomWall(int x, int y){
        // 1 means right, 2 means left, 3 means down, 4 means up and 0 means there is no available cell//
    
        vector<int> direction;

        if(x != row - 1){
            if(!_maze[x + 1][y].ifChecked()) direction.push_back(3);
        }
        if(x != 0){
            if(!_maze[x - 1][y].ifChecked()) direction.push_back(4);
        }
        if(y != col - 1){
            if(!_maze[x][y + 1].ifChecked()) direction.push_back(1);
        }
        if(y != 0){
            if(!_maze[x][y - 1].ifChecked()) direction.push_back(2);
        }
        
        if(direction.size() == 0) return 0;

        int ind = rand() % direction.size();

        return direction[ind];
        
    }

    int selectRandomDirection(int x, int y){

        // 1 means right, 2 means left, 3 means down, 4 means up and 0 means there is no available cell//

        vector<int> direction;

        if(y != col - 1){
            if(!_maze[x][y + 1].getLeftWall()){
                if(!_maze[x][y + 1].ifChecked2()) direction.push_back(1);
            }
        }
        if(y != 0){
            if(!_maze[x][y - 1].getRightWall()){
                if(!_maze[x][y - 1].ifChecked2()) direction.push_back(2);
            }
        }
        if(x != row - 1){
            if(!_maze[x + 1][y].getUpWall()){
                if(!_maze[x + 1][y].ifChecked2()) direction.push_back(3);
            }
        }
        if(x != 0){
            if(!_maze[x - 1][y].getDownWall()){
                if(!_maze[x - 1][y].ifChecked2()) direction.push_back(4);
            }
        }

        if(direction.size() == 0) return 0;

        int ind = rand() % direction.size();

        return direction[ind];
    }

    cell getcell(int x, int y){
        return _maze[x][y];
    }

    vector<pair<int,int>> findPath(int i, int j, int end_x, int end_y){
        stack<cell*> cache;

        cell * curr_cell = &_maze[i][j];

        curr_cell->Checked2();

        cache.push(curr_cell);

        vector<pair<int,int>> path_memorizer;

        while(!cache.empty()){
            curr_cell = cache.top();

            int x = curr_cell->getX();
            int y = curr_cell->getY();

            if(x == end_x && y == end_y){
                while(!cache.empty()){
                    cell* tmp = cache.top();
                    cache.pop();
                    path_memorizer.insert(path_memorizer.begin(), {tmp->getX(), tmp->getY()});
                }
                resetMaze();
                return path_memorizer;
            }

            int path = selectRandomDirection(x, y);

            if(path == 0){
                cache.pop();

            }
            else if(path == 1){
                _maze[x][y + 1].Checked2();
                curr_cell = &_maze[x][y + 1];
                cache.push(curr_cell);
            }
            else if(path == 2){
               _maze[x][y - 1].Checked2();
                curr_cell = &_maze[x][y - 1];
                cache.push(curr_cell);
            }
            else if(path == 3){
                _maze[x + 1][y].Checked2();
                curr_cell = &_maze[x + 1][y];
                cache.push(curr_cell);
            }
            else if(path == 4){
                _maze[x - 1][y].Checked2();
                curr_cell = &_maze[x - 1][y];
                cache.push(curr_cell);
            }
        }
        resetMaze();
        return path_memorizer;
    }

    void resetMaze(){
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++) _maze[i][j].reset2();
        }
    }

};