int minimumTotal(vector<vector<int> >& triangle) {
       int temp;

       for (int i = 0; i < triangle.size()-1; i++)
       {

           for (int j = i , l = 0; l < triangle[i].size(); l++ )
           {
               if (l == 0)
               {
                    temp = triangle[j+1][l+1];
                    triangle[j+1][l] = triangle[j][l] + triangle[j+1][l];
                    triangle[j+1][l+1] =  triangle[j][l] + triangle[j+1][l+1];
               }
               else
               {
                    if (triangle[j][l] + temp < triangle[j+1][l])
                        triangle[j+1][l] = triangle[j][l] + temp;

                    temp = triangle[j+1][l+1];
                    triangle[j+1][l+1] =  triangle[j][l] + triangle[j+1][l+1];
               }


           }
       }
       int mins ;
       int row = triangle.size()-1;
       for (int i = 1; i < triangle[row].size();i++)
       {
           //cout << triangle[row][i] << " ";
           if (triangle[row][i] > triangle[row][i-1])
           {
               temp = triangle[row][i];
               triangle[row][i] = triangle[row][i-1];
               triangle[row][i-1] = temp;
           }
       }
       return triangle[row][triangle[row].size()-1];

    }