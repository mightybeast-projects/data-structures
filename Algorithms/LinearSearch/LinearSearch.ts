export default function linearSearch(haystack: number[], needle: number): boolean {
    for (var i = 0; i < haystack.length; i++) {
        if (haystack[i] === needle)
            return true;
    }
    
    return false;
}