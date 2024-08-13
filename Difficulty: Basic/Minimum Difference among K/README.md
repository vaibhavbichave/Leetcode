<h2><a href="https://www.geeksforgeeks.org/problems/minimum-difference-among-k5805/1?page=1&company=Amazon&difficulty=Basic&status=unsolved&sortBy=difficulty">Minimum Difference among K</a></h2><h3>Difficulty Level : Difficulty: Basic</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an array<span style="box-sizing: border-box; margin: 0px; padding: 0px;"> </span><strong>arr[] </strong>of&nbsp;integers and a positive number&nbsp;<strong>k</strong>. We are allowed to take any k integers from the given array. The task is to find the minimum possible value of the difference between the maximum and minimum of <strong>k</strong> numbers.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr[] = [10, 100, 300, 200, 1000, 20, 30], k=3
<strong>Output: </strong>20
<strong>Explanation</strong>: 20 is the minimum possible difference between any maximum and minimum of any k numbers.Given k = 3, we get the result 20 by selecting integers {10, 20, 30}.max(10, 20, 30) - min(10, 20, 30) = 30 - 10 = 20.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr[] = [1, 1], k=2
<strong>Output: </strong>0
<strong>Explanation</strong>: max({1,1}) - min({1,1}) = 1 - 1 = 0
</span></pre>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(nlogn)<br><strong>Expected Auxiliary Space:</strong> O(1)</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1≤ arr.size() ≤ 10<sup>5<br></sup></span><span style="font-size: 18px;">1≤ arr[i] ≤ 10<sup>5<br></sup></span><span style="font-size: 18px;">0 &lt; k ≤ n<br></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Sorting</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;