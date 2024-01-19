const std = @import("std");

const UnionFind = struct {
    p: []i32,
    rank: []i32,
    setSize: []i32,
    numSets: i32,

    pub fn init(size: i32) UnionFind {
        var p: [size]i32 = undefined;
        for (0..size - 1) |i| {
            p[i] = i;
        }
        return UnionFind{
            .p = p,
            .rank = [size]i32{0},
            .setSize = [size]i32{1},
            .numSets = size,
        };
    }

    pub fn findSet(self: UnionFind, i: i32) i32 {
        return if (self.p[i] == i) {
            return i;
        } else {
            self.p[i] = self.findSet(self.p[i]);
            return self.p[i];
        };
    }

    pub fn isSameSet(self: UnionFind, i: i32, j: i32) bool {
        return self.findSet(i) == self.findSet(j);
    }

    pub fn sizeOfSet(self: UnionFind, i: i32) i32 {
        return self.setSize[i];
    }

    pub fn unionSet(self: UnionFind, i: i32, j: i32) void {
        if (self.isSameSet(i, j)) {
            return;
        }
        var x = self.findSet(i);
        var y = self.findSet(j);
        if (self.rank[x] > self.rank[y]) {
            var temp: i32 = x;
            x = y;
            y = temp;
        }
        self.p[x] = y;
        if (self.rank[x] == self.rank[y]) {
            self.rank[y] += 1;
        }
        self.setSize[y] += self.setSize[x];
        self.numSets -= 1;
    }
};
