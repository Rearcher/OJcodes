// first bad version
/**
 * Definition for isBadVersion()
 * 
 * @param {integer} version number
 * @return {boolean} whether the version is bad
 * isBadVersion = function(version) {
 *     ...
 * };
 */

/**
 * @param {function} isBadVersion()
 * @return {function}
 */
var solution = function(isBadVersion) {
    /**
     * @param {integer} n Total versions
     * @return {integer} The first bad version
     */
    return function(n) {
        var left = 1, right = n, mid;
        while (left < right) {
            mid = left + Math.floor((right-left)/2);
            if (!isBadVersion(mid)) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    };
};
