/*


    #include <iostream>
    #include <fstream>
    #include <queue>
    #include <vector>

    using namespace std;

    void cargar(ifstream *file, long long grid[20][20] )
    {
        for(int i = 0; i < 20; i++)
            for(int j = 0; j < 20; j++)
                 *file >> grid[i][j];
    }

    void print(queue<long long> nums)
    {
        while(!nums.empty())
        {
            cout << nums.front() << " * ";
            nums.pop();
        }
        cout << " 1  = ";

    }

    void renew(long long *tmp, queue<long long> nums)
    {
        *tmp = 1;
        while(!nums.empty())
        {
            if( nums.front() ) *tmp *= nums.front();
            nums.pop();
        }
    }

    queue<long long> recordar_pareja(queue<long long> nums)
    {
        queue<long long> nueva;
        for(int i = 0; i < 4; i++)
        {
            nueva.push(nums.front());
            nums.pop();
        }
        return nueva;
    }

    int main()
    {
        long long grid[20][20], larger(1), tmp(1);
        queue<long long> nums, lol, best;
        ifstream file("num.txt");
        cargar(&file, grid);

        for(int i = 0; i < 20; i++)
            {
                for(int j = 0, aux(0); j < 20; j++)
                    {
                        //if (j > 3) print (nums);
                        nums.push(grid[i][j]);
                        if( j <= 3)
                        {
                            tmp *= nums.back();
                            if(!tmp) aux++;

                        }
                        else
                        {
                            //cout << tmp << endl;
                           // cin.get();
                            if (larger < tmp ) larger = tmp, lol = recordar_pareja(nums);
                            if ( nums.front() )tmp /= nums.front();

                            if (!nums.back()) aux = 0;
                            if( !tmp && aux == 4 ) renew(&tmp, nums), aux = 0;
                            else
                                tmp *= nums.back();

                            if(!tmp) aux++;

                            nums.pop();
                        }
                }
                //print(nums); cout << tmp << endl; //cin.get();
                if(larger < tmp) larger = tmp, lol = recordar_pareja(nums);;
                while(!nums.empty()) nums.pop();
                tmp = 1;
            }
        print(lol);//78*78*96*83 = 48477312
        cout << larger << endl;

        for(int i = 0; i < 20; i++)
            {
                for(int j = 0, aux(0); j < 20; j++)
                    {
                        //if (j > 3) print (nums);
                        nums.push(grid[j][i]);
                        if( j <= 3)
                        {
                            tmp *= nums.back();
                            if(!tmp) aux++;

                        }
                        else
                        {
                            //cout << tmp << endl;
                           // cin.get();
                            if (larger < tmp ) larger = tmp, lol = recordar_pareja(nums);
                            if ( nums.front() )tmp /= nums.front();

                            if (!nums.back()) aux = 0;
                            if( !tmp && aux == 4 ) renew(&tmp, nums), aux = 0;
                            else
                                tmp *= nums.back();

                            if(!tmp) aux++;

                            nums.pop();
                        }
                }
                //print(nums); cout << tmp << endl; //cin.get();
                if(larger < tmp) larger = tmp, lol = recordar_pareja(nums);;
                while(!nums.empty()) nums.pop();
                tmp = 1;
            }

                    //66*91*88*97 = 51267216
        print(lol);
        cout << larger << endl;

        vector< vector<int> > grilla(2*20-1);
        for (int diagonales = 0; diagonales < 2 * 20 - 1; ++diagonales) {
            //printf("Slice %d: ", slice);
            int z = diagonales < 20 ? 0 : diagonales - 20 + 1;
            for (int j = z; j <= diagonales - z; ++j) {
                  grilla[diagonales].push_back(grid[j][diagonales-j]);
            }
        }

        for(int i = 0; i < 20; i++)
            {
                for(int j = 0, aux(0); j < grilla[i].size(); j++)
                    {
                        //if (j > 3) print (nums);
                        nums.push(grilla[i][j]);
                        if( j <= 3)
                        {
                            tmp *= nums.back();
                            if(!tmp) aux++;

                        }
                        else
                        {
                            //cout << tmp << endl;
                           // cin.get();
                            if (larger < tmp ) larger = tmp, lol = recordar_pareja(nums);
                            if ( nums.front() )tmp /= nums.front();

                            if (!nums.back()) aux = 0;
                            if( !tmp && aux == 4 ) renew(&tmp, nums), aux = 0;
                            else
                                tmp *= nums.back();

                            if(!tmp) aux++;

                            nums.pop();
                        }
                }
                //print(nums); cout << tmp << endl; //cin.get();
                if(larger < tmp) larger = tmp, lol = recordar_pareja(nums);;
                while(!nums.empty()) nums.pop();
                tmp = 1;
            }
            print(lol);
        cout << larger << endl;


        return 0;

    }

*/
