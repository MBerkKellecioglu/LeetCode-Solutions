#include"maze.cpp"
#include<fstream>
#include<string>

using namespace std;

int main(){

    srand(time(0));

    int M, N, K;
    
    cout << "Please enter your row, collumn and number of mazes";
    cin >> M >> N >> K;
    cout << endl;

    vector<maze> all_mazes;

    for(int i = 0; i < K; i++){
        string maze_name = "maze_" + to_string(i + 1) + ".txt";

        ofstream outputFile(maze_name);

        outputFile << M << " " << N << "\n";

        maze tmp_maze(M,N);

        all_mazes.push_back(tmp_maze);

        for(int x = M - 1; x > -1; x--){
            for(int y = 0; y < N; y++){
                cell tmp = tmp_maze.getcell(x, y);
                int l = tmp.getLeftWall(), r = tmp.getRightWall(), u = tmp.getUpWall(), d = tmp.getDownWall();

                outputFile << "x=" << M-x-1 << " " << "y=" << y << " "<< "l=" << l << " " << "r=" << r << " " << "u=" << u << " " << "d=" << d << "\n"; 
            }
        }
    }

    int start_x, start_y, end_x, end_y, num;

    cout << "Please enter entry point, exit point and which maze we are going to search";
    cin >> start_x >> start_y >> end_x >> end_y >> num;

    vector<pair<int,int>> tmp = all_mazes[num - 1].findPath(abs((M-1) - start_x), start_y, abs((M - 1) - end_x), end_y);

    string tmp_s = "maze_" + to_string(num) + "_path_" + to_string(start_x) + "_" + to_string(start_y) + "_" + to_string(end_x) + "_" + to_string(end_y) + ".txt";

    ofstream outputFile(tmp_s);

    for(auto elements : tmp){
        outputFile << abs((M-1) - elements.first) << " " << elements.second << "\n";
    }


    return 0;
}