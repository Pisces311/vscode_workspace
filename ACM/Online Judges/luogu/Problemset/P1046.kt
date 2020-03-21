fun main() {
    var a = readLine()!!.split(' ').map(String::toInt)
    var n = readLine()!!.toInt()
    n += 30
    var ans = 0
    for (i in a) if (i <= n) ++ans
    println(ans)
}