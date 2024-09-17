class Solution {
    func countWords(_ words1: [String], _ words2: [String]) -> Int {        
        var counts1: [String: Int] = [:]
        var counts2: [String: Int] = [:]
        
        words1.forEach { counts1[$0, default: 0] += 1 }
        words2.forEach { counts2[$0, default: 0] += 1 }
        
        return words1.filter {(counts1[$0] == 1 && counts2[$0] == 1)}.count       
    }
}