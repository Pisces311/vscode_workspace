fun main() {
    var (L, M) = readLine()!!.split(' ').map(String::toInt)
    var a = IntArray(L + 1)
    while (M-- > 0) {
        var (l, r) = readLine()!!.split(' ').map(String::toInt)
        for (i in l..r) a[i] = 1
    }
    var ans = 0
    for (i in 0..L) if (a[i] == 0) ++ans
    println(ans) 
}