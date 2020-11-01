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
  const [n, k] = split(lines[0]);
  const a = initArray(2, 0, n, n);
  for (let i = 0; i < n; i++) {
    const line = lines[i + 1];
    const ai = split(line);
    for (let j = 0; j < n; j++) a[i][j] = ai[j];
  }
  return { n, k, a };
}

function solve(n, k, a) {
  const f = initArray(2, 0, n + 1, n + 1);
  for (let i = 1; i <= n; i++) {
    for (let j = 1; j <= n; j++) {
      f[i][j] = a[i - 1][j - 1] + f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
    }
  }
  let res = 0;
  for (i = k; i <= n; i++) {
    for (j = k; j <= n; j++) {
      const s = f[i][j] - f[i - k][j] - f[i][j - k] + f[i - k][j - k];
      res = Math.max(res, s);
    }
  }

  console.log(res);
}

function main(stdin_input) {
  const { n, k, a } = input(stdin_input);
  solve(n, k, a);
}
