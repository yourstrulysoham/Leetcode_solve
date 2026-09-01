/**
 * @param {string[]} classroom
 * @param {number} energy
 * @return {number}
 */
var minMoves = function(classroom, energy) {

    const m = classroom.length;
    const n = classroom[0].length;

    let sx = -1;
    let sy = -1;
    let litterCount = 0;

    // we give each litter cell a bit index.
    const litterId = Array.from({ length: m }, () => Array(n).fill(-1));

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (classroom[i][j] === 'S') {
                sx = i;
                sy = j;
            } else if (classroom[i][j] === 'L') {
                litterId[i][j] = litterCount++;
            }
        }
    }

    if (litterCount === 0) return 0;

    const fullMask = (1 << litterCount) - 1;

    // bestEnergy[x][y][mask] = maximum energy we've had at (x, y)
    //   after collecting the litter represented by mask.
    const bestEnergy = Array.from({ length: m }, () =>
        Array.from({ length: n }, () =>
            Array(1 << litterCount).fill(-1)
        )
    );

    // [x, y, currentEnergy, mask, steps]
    const queue = [[sx, sy, energy, 0, 0]];
    let head = 0;

    bestEnergy[sx][sy][0] = energy;

    const dirs = [ [1, 0], [-1, 0], [0, 1], [0, -1] ];

    while (head < queue.length) {
        const [x, y, curEnergy, mask, steps] = queue[head++];

        // Collected all litter
        if (mask === fullMask) {
            return steps;
        }

        // No energy -> cannot move unless we're already on R.
        // But if we're on R, energy would already have been reset when we entered it.
        if (curEnergy === 0) {
            continue;
        }

        for (const [dx, dy] of dirs) {
            const nx = x + dx;
            const ny = y + dy;

            // Outside grid or obstacle
            if ( nx < 0 || nx >= m || ny < 0 || ny >= n || classroom[nx][ny] === 'X') {
                continue;
            }

            // Every move costs 1 energy.
            let nextEnergy = curEnergy - 1;
            let nextMask = mask;

            // Reset area
            if (classroom[nx][ny] === 'R') {
                nextEnergy = energy;
            }

            // Collect litter
            if (classroom[nx][ny] === 'L') {
                const bit = litterId[nx][ny];
                nextMask |= (1 << bit);
            }

            // If we've already reached this (x, y, mask)
            // with >= energy, this state is useless.
            if (nextEnergy <= bestEnergy[nx][ny][nextMask]) {
                continue;
            }

            bestEnergy[nx][ny][nextMask] = nextEnergy;

            queue.push([ nx, ny, nextEnergy, nextMask, steps + 1 ]);
        }
    }

    return -1;
};