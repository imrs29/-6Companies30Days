//Given a matrix of size r*c. Traverse the matrix in spiral form. 

 // code here 
        int row_start = 0, row_end = r-1, col_start = 0, col_end = c-1;
        vector<int>ans;
	while(row_start <= row_end && col_start <= col_end){

		//for row start
		for(int col = col_start; col <= col_end; col++)
			ans.push_back(matrix[row_start][col]);
			row_start++;

		//for col_end

		for(int row = row_start; row <= row_end; row++)
			ans.push_back(matrix[row][col_end]);
		col_end--;

		//for row end
		if(row_start <= row_end){
		for(int col = col_end; col >= col_start; col--)
			ans.push_back(matrix[row_end][col] );
		row_end--;
		}

		//for col start
        if(col_start <= col_end){
		for(int row = row_end; row >= row_start; row--)
			ans.push_back(matrix[row][col_start]);
		col_start++;
        }
	}
        return ans;
