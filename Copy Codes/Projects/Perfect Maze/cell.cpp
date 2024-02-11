using namespace std;

class cell{

private:
    int x;
    int y;
    int l_wall;
    int r_wall;
    int u_wall;
    int d_wall;
    int checked_flag;
    int checked_flag2;

public:

    cell(){
        x = 0;
        y = 0;
        l_wall = 1;
        r_wall = 1;
        u_wall = 1;
        d_wall = 1;
        checked_flag = 0;
        checked_flag2 = 0;
    }

    cell(int i, int j){
        x = i;
        y = j;
        l_wall = 1;
        r_wall = 1;
        u_wall = 1;
        d_wall = 1;
        checked_flag = 0;
        checked_flag2 = 0;
    }

    int getX(){
        return x;
    }
    
    int getY(){
        return y;
    }

    int getLeftWall(){
        return l_wall;
    }

     int getRightWall(){
        return r_wall;
    }

     int getUpWall(){
        return u_wall;
    }

     int getDownWall(){
        return d_wall;
    }

    void breakLeftWall(){
        l_wall = 0;
    }

    void breakRightWall(){
        r_wall = 0;
    }

    void breakUpWall(){
        u_wall = 0;
    }

    void breakDownWall(){
        d_wall = 0;
    }

    void Checked(){
        checked_flag = true;
    }

    bool ifChecked(){
        return checked_flag;
    }

    bool ifChecked2(){
        return checked_flag2;
    }

    void Checked2(){
        checked_flag2 = true;
    }

    void reset2(){
        checked_flag2 = false;
    }

};
