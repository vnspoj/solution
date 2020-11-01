process.stdin.resume();
process.stdin.setEncoding("utf-8");
let stdin_input = "";
process.stdin.on("data", function (input) {
  stdin_input += input;
});
process.stdin.on("end", function () {
  main(stdin_input);
});

function split(line = "") {
  return line
    .split(" ")
    .map((s) => {
      try {
        return parseInt(s, 10);
      } catch (err) {
        return null;
      }
    })
    .filter((n) => !!n);
}

function initArray(nDimensions = 2, defaultValue = 0, ...nSizes) {
  if (nDimensions == 0) return defaultValue;
  const a = [];
  const restNSizes = nSizes.slice(1);
  for (let i = 0; i < nSizes[0]; i++) {
    const child = initArray(nDimensions - 1, defaultValue, ...restNSizes);
    a.push(child);
  }
  return a;
}

function input(stdin_input) {
  const lines = stdin_input.split("\n");
  const [n, m, k] = split(lines[0]);
  const a = initArray(1, 0, m + 1);
  for (let i = 0; i < n; i++) {
    const line = lines[i + 1];
    const [room] = split(line);
    a[room]++;
  }
  return { m, k, a };
}

const P = (n, k) => {
  const p = Math.floor(n / k);
  const y = n - p * k;
  const x = k - y;
  return (x * p * (p + 1)) / 2 + (y * (p + 1) * (p + 2)) / 2;
};

function solve(m, k, a) {
  const f = initArray(2, 0, m + 1, k + 1);
  for (let i = 1; i <= m; i++) {
    for (let j = 0; j <= k; j++) {
      f[i][j] = P(a[i], j + 1);
    }
  }
  const g = initArray(2, 0, m + 1, k + 1);
  for (let j = 0; j <= k; j++) g[1][j] = f[1][j]; // room 1
  for (let i = 2; i <= m; i++) {
    for (let j = 0; j <= k; j++) {
      g[i][j] = g[i - 1][j] + f[i][0];
      for (let t = 1; t <= j; t++) {
        g[i][j] = Math.min(g[i][j], g[i - 1][j - t] + f[i][t]);
      }
    }
  }

  console.log(g[m][k]);
}

function main(stdin_input) {
  const { m, k, a } = input(stdin_input);
  solve(m, k, a);
}
