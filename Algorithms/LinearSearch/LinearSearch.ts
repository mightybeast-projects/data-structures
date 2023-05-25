export default function linearSearch(arr: number[], value: number): boolean {
    for (var i = 0; i < arr.length; i++)
        if (arr[i] === value)
            return true;
    
    return false;
}