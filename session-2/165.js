// compare version number
/**
 * @param {string} version1
 * @param {string} version2
 * @return {number}
 */
var compareVersion = function(version1, version2) {
    var num1, num2;
    var begin1=0, end1=0, begin2=0, end2=0;
    while (end1 < version1.length && end2 < version2.length) {
        while (end1 < version1.length && version1[end1] !== '.') end1++;
        while (end2 < version2.length && version2[end2] !== '.') end2++;
        num1 = parseInt(version1.slice(begin1, end1));
        num2 = parseInt(version2.slice(begin2, end2));
        
        if (num1 > num2) return 1;
        else if (num1 < num2) return -1;
        else {
            end1++;
            end2++;
            begin1 = end1;
            begin2 = end2;
        }
    }
    
    while (end1 < version1.length) {
        while (end1 < version1.length && version1[end1] !== '.') end1++;
        num1 = parseInt(version1.slice(begin1, end1));
        if (num1 !== 0) return 1;
        else {
            end1++;
            begin1 = end1;
        }
    }
    
    while (end2 < version2.length) {
        while (end2 < version2.length && version2[end2] !== '.') end2++;
        num2 = parseInt(version2.slice(begin2, end2));
        if (num2 !== 0) return -1;
        else {
            end2++;
            begin2 = end2;
        }
    }
    
    return 0;
};
