class ArrayWrapper {
    _nums: number[];

    constructor(nums: number[]) {
        this._nums = nums;
    }
    
    valueOf(): number {
        return this._nums.reduce((total, curr) => total + curr, 0);
    }
    
    toString(): string {
        let result: string = "[";
        for (let i = 0; i < this._nums.length; i++) {
            result += this._nums[i].toString();
            if(i !== this._nums.length - 1) {
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