class Solution {
    func pivotInteger(_ n: Int) -> Int {
        for i in 1...n {
            if i*i == n*(n+1)/2 {
                return i
            }
        }

        return -1
    }
}