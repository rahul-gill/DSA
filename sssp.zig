const std = @import("std");
const Allocator = std.mem.Allocator;

const QueueItem = struct {
    node: usize,
    depth: usize,
};

const Queue = struct {
    items: [usize]usize = undefined,
    head: usize = 0,
    tail: usize = 0,
    capacity: usize,
    allocator: *Allocator,
};

pub fn init(allocator: *Allocator, capacity: usize) Queue {
    const items: [usize]usize = undefined;
    return Queue{ .items = items, .capacity = capacity, .allocator = allocator };
}

pub fn enqueue(self: *Queue, item: usize) void {
    if (self.tail == self.capacity) {
        return;
    }
    self.items[self.tail] = item;
    self.tail += 1;
}

pub fn dequeue(self: *Queue) ?usize {
    if (self.head == self.tail) {
        return null;
    }
    const item = self.items[self.head];
    self.head += 1;
    return item;
}

fn bfs(graph: [][]usize, startNode: usize) void {
    const allocator = std.heap.page_allocator;
    var visited = try std.mem.Array([]bool, graph.len);
    var queue = init(&allocator, graph.len);
    
    enqueue(startNode);
    visited[startNode] = true;
    
    while (true) {
        const currentNode = dequeue();
        if (currentNode == null) break;
        
        // Process the current node here
        const node = currentNode.*;
        std.debug.print("{d} ", .{node});
        
        for (graph[node]) |neighbor| {
            if (!visited[neighbor]) {
                enqueue(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

pub fn main() void {
    var graph: [6][]usize = undefined;
    gra[0] = []
        [1, 2],
        [0, 3, 4],
        [0, 5],
        [1],
        [1],
        [2]
    ;

    std.debug.print("BFS starting from node 0: ");
    bfs(graph, 0);
    std.debug.print("\n");
}
