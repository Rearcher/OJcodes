/* minimum path sum */
/**
 * @param {number[][]} grid
 * @return {number}
 */
var minPathSum = function(grid) {
    if (grid.length === 0) return 0;
    
    var m = grid.length;
    var n = grid[0].length;
    var res = [], i, j;
    
    for (i = 0; i < m; i += 1) {
        res.push([]);
        for (j = 0; j < n; j += 1)
            res[i].push(0);
        
    }
    
    res[0][0] = grid[0][0];
    for (i = 1; i < m; i += 1) {
        res[i][0] = res[i-1][0] + grid[i][0];
    }    
    for (j = 1; j < n; j += 1) {
        res[0][j] = res[0][j-1] + grid[0][j];
    }
    
    for (i = 1; i < m; i += 1) {
        for (j = 1; j < n; j += 1) {
            res[i][j] = Math.min(res[i-1][j], res[i][j-1]) + grid[i][j];
        }
    }
    
    return res[m-1][n-1];
};
