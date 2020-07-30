#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
using namespace std;

namespace matrix {
	//图的存储：顶点集合、边集合 -- 两个顶点 + 边的权值
	//1.邻接矩阵
	template <class V, class W, bool D = false>
	class Graph {
	public:
		Graph(const V* a, int n) {
			_vertexs.reserve(n);
			_edges.resize(n);
			for (int i = 0; i < n; ++i) {
				_edges[i].resize(n, W());
				_vertexs.push_back(a[i]);
				_vertexIndex[a[i]] = i;
			}
		}

		int GetVertexIndex(const V& v) {
			//for (int i = 0; i < _vertexs.size(); ++i) {
			//	if (_vertexs[i] == v) {
			//		return i;
			//	}
			//}

			if (_vertexIndex.find(v) != _vertexIndex.end()) {
				return _vertexIndex[v];
			}

			throw invalid_argument("非法顶点");
			//返回错误码   抛异常    两种方式
			//return -1;
		}

		void AddEdge(const V& src, const V& dst, const W& w) {
			//获取点的下标
			int srcIndex = GetVertexIndex(src);
			int dstIndex = GetVertexIndex(dst);
			_edges[srcIndex][dstIndex] = w;
			//无向图 -- 得添加两条边
			if (D == false) {
				_edges[dstIndex][srcIndex] = w;
			}
		}
		void _DFS(int srcindex, vector<bool>& visited) {
			visited[srcindex] = true;
			cout << _vertexs[srcindex] << ": " << srcindex << "->";
			for (int i = 0; i < _edges[srcindex].size(); ++i) {
				if (_edges[srcindex][i] != W() && visited[i] == false) {
					_DFS(i, visited);
				}
			}
		}

		void DFS(const V& src) {
			int srcIndex = GetVertexIndex(src);
			vector<bool> visited;
			visited.resize(_vertexs.size(), false);
			_DFS(srcIndex, visited);
		}

		void BFS(const V& src) {
			int srcindex = GetVertexIndex(src);
			vector<bool> visited;
			visited.resize(_vertexs.size(), false);
			queue<int> q;
			q.push(srcindex);
			visited[srcindex] = true;
			int size = 0;
			while (!q.empty()) {
				size = q.size();
				while (size--) {
					int front = q.front();
					q.pop();
					cout << _vertexs[front] << ": " << front << " ";
					//visited[front] = true;
					//和它相连的所有的边都遍历
					for (int i = 0; i < _edges[front].size(); ++i) {
						if (_edges[front][i] != W() && visited[i] == false) {
							q.push(i);
							visited[i] = true;
						}
					}
				}
				cout << endl;
			}
		}






	private:
		vector<V> _vertexs;			//顶点集合
		vector<vector<W>> _edges;	//边的集合
		map<V, int> _vertexIndex;	//顶点 -- 下标映射关系
	};

	void TestGraph() {
		string a[] = { "库里","汤普生","詹姆斯","韦德", "保罗","杜兰特" };
		Graph<string, int> g(a, 6);
		g.AddEdge("库里", "汤普生", 99);
		g.AddEdge("詹姆斯", "韦德", 100);
		g.AddEdge("詹姆斯", "保罗", 98);
		g.AddEdge("詹姆斯", "库里", 80);
		g.AddEdge("杜兰特", "库里", 90);
		g.AddEdge("杜兰特", "汤普生", 90);
		cout << "DFS：";
		g.DFS("詹姆斯");
		cout << endl << "BFS：";
		g.BFS("詹姆斯");
	}
}


namespace  linktable {
	//2.邻接表

	template <class W>
	struct LinkEdge {
		int _dst;
		int _src;
		W _w;
		LinkEdge* next = nullptr;
	};

	template <class V, class W, bool D = false>
	class Graph {
		typedef LinkEdge<W> Edge;
	public:
		Graph(const V* a, int n) {
			_vertexs.reserve(n);
			_linktable.resize(n, nullptr);
			for (int i = 0; i < n; ++i) {
				_linktable[i].resize(n, nullptr);
				_vertexs.push_back(a[i]);
				_vertexIndex[a[i]] = i;
			}
		}

		int GetVertexIndex(const V& v) {
			//for (int i = 0; i < _vertexs.size(); ++i) {
			//	if (_vertexs[i] == v) {
			//		return i;
			//	}
			//}

			if (_vertexIndex.find(v) != _vertexIndex.end()) {
				return _vertexIndex[v];
			}

			throw invalid_argument("非法顶点");
			//返回错误码   抛异常    两种方式
			//return -1;
		}

		void _AddEdge(int srcIndex, int dstIndex, const W& w) {
			Edge* edge = new Edge;
			edge->_dst = dstIndex;
			edge->_src = srcIndex;
			edge->_w = w;
			//像哈希桶下挂节点一样 -- 头插的操作
			edge->next = _linktable[srcIndex];
			_linktable[srcIndex] = edge;

		}

		void AddEdge(const V& src, const V& dst, const W& w) {
			int srcIndex = GetVertexIndex(src);
			int dstIndex = GetVertexIndex(dst);

			_AddEdge(srcIndex, dstIndex, w);
			if (D == false) {
				_AddEdge(dstIndex, srcIndex, w);
			}
		}

	private:
		vector<V> _vertexs;			//顶点集合
		vector<Edge*>  _linktable;	//边的集合，邻接表
		map<V, int> _vertexIndex;	//顶点 -- 下标映射关系
	};
}



int main() {
	matrix::TestGraph();
	return 0;
}

//深度和广度遍历的都是顶点
//深度优先：一条道走到黑			-- 递归
//广度优先：某个点为起点，发散遍历	-- 队列




//邻接矩阵和邻接表的优缺点各是什么？
//邻接矩阵：
//	1.适合存储边很多的场景 -- 这样邻接矩阵的利用率很高
//	2.适合查找一条边在不在以及更新边的权值
//邻接表：
//	1.适合边相对比较稀疏的图
//	2.经常要遍历图中的所有边，邻接表比较快 -- 每个点对应的边一目了然

