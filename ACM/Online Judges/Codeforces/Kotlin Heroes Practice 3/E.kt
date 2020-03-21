fun main() {
    var (n, k) = readLine()!!.split(' ').map(String::toInt)
    var a = readLine()!!.split(' ').map(String::toInt)
    var arr = ArrayList<Node>()
    for (i in 0 until n)
        arr.add(Node(a[i], i))
    arr.sortBy { it.value }
    var sub = IntArray(n) { 0 }
    var ans = IntArray(n) { 0 }
    while (k-- > 0) {
        var (u, v) = readLine()!!.split(' ').map(String::toInt)
        u--;v--
        if (a[u] > a[v]) sub[u]++
        else if (a[v] > a[u]) sub[v]++
    }
    var j = 0
    for (i in 0 until n) {
        while (arr[j].value < arr[i].value) j++
        ans[arr[i].idx] = j - sub[arr[i].idx]
    }
    ans.forEach { print("$it ") }
    println()
}

class Node(value: Int, idx: Int) {
    var value = 0
    var idx = 0

    init {
        this.value = value
        this.idx = idx
    }
}