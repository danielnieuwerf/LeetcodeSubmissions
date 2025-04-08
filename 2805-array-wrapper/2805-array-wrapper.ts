class ArrayWrapper {
    _nums: number[];

    constructor(nums: number[]) {
        this._nums = nums;
    }
    
    valueOf(): number {
        return this._nums.reduce((total, curr) => total + curr, 0);
    }
    
    toString(): string {
        let result = "[";
        let n = this._nums.length;
        for (let i = 0; i < n; i++) {
            result += this._nums[i].toString();
            if(i !== n - 1) {
                result += ",";
            }
        }
        return result + "]";
    }
};

/**
 * const obj1 = new ArrayWrapper([1,2]);
 * const obj2 = new ArrayWrapper([3,4]);
 * obj1 + obj2; // 10
 * String(obj1); // "[1,2]"
 * String(obj2); // "[3,4]"
 */