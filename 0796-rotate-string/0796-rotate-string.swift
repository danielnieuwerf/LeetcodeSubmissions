class Solution {
    func rotateString(_ s: String, _ goal: String) -> Bool {
        guard s.count == goal.count else { return false }
        var possible = false
        (0..<s.count).forEach {
            var i = s.index(s.endIndex, offsetBy: -$0)            
            if goal == s.suffix(from: i) + s[..<i] {
                possible = true
            }
        }
        return possible
    }
}