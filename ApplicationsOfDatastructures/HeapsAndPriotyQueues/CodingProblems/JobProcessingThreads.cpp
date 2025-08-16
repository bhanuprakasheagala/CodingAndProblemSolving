#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());

    // Priority queue to store (next_free_time, worker_id)
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    // Initialize priority queue with workers, all are free at time 0
    for (int i = 0; i < num_workers_; ++i) {
      pq.push({0, i});  // (next_free_time, worker_id)
    }

    for (int i = 0; i < jobs_.size(); ++i) {
      int job_duration = jobs_[i];
      
      // Get the worker with the earliest available time
      auto [available_time, worker_id] = pq.top();
      pq.pop();
      
      // Assign the job to this worker and record the start time
      assigned_workers_[i] = worker_id;
      start_times_[i] = available_time;
      
      // Update the worker's next available time
      pq.push({available_time + job_duration, worker_id});
    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
