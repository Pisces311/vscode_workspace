fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt)
    for (i in 0 until n) {
        var ans = 0
        for (j in 0 until i) {
            if (a[j] < a[i]) ++ans
        }
        print("$ans ")
    }
}