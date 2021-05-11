#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	// create 'visited' bool vector with all 'false' values
	vector<bool> visited(n, false);
	// create 'cnt' to count the number of permutation cycles
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			// if it's not yet, visited then visit this i-th position
			visited[i] = true;
			// start visiting the position at index 'a[i]' - 1
			int index = a[i] - 1;
			// create a while-loop until all values that were not visited are visited
			while (!visited[index]) {
				// visit the position of the new index
				visited[index] = true;
				// update the 'index' variable using number that was visited
				index = a[index] - 1;
			}
			// increment 'cnt'
			cnt++;
		}
	}
	// print the value of 'cnt'
	cout << cnt << '\n';
	// reset the 'visited' vector back to all 'false' values
	fill(visited.begin(), visited.end(), false);
	// this loop below is the same process as the one above but this time print the values
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			// print the current position that is being visited together with the value
			cout << i + 1 << " " << a[i] << " ";
			visited[i] = true;
			int index = a[i] - 1;
			while (!visited[index]) {
				visited[index] = true;
				// print the value that this being visited
				cout << a[index] << " ";
				index = a[index] - 1;
			}
			cout << '\n';
		}
	}
	return 0;
}
