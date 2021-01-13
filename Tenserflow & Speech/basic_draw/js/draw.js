let textHere = document.getElementById('textHere'); // display data

const canvas1 = document.getElementById('canvas1');
const context = canvas1.getContext('2d');

canvas1.style.zIndex = 2;
canvas1.width = screen.width;
canvas1.height = screen.height;
canvas1.style.zIndex = 2;
context.translate(screen.width, 0); // flip screen horizontal
context.scale(-1, 1); // flip screen horizontal

context.lineJoin = 'round';
context.lineCap = 'round';
context.lineWidth = 5;
context.strokeStyle = '#ac0000';

let width = canvas1.width;
let height = canvas1.height;

let lastX = 0;
let lastY = 0;

const clearDrawing = () => {
  context.clearRect(0, 0, canvas1.width, canvas1.height);
}


let A, B, C, S;
A = new Point(new Vector2d(100, 100), 20, "Magenta", "dragable", false);
B = new Point(new Vector2d(width / 3, height / 3), 20, "blue", "Ball2", true);
C = new Point(new Vector2d(width / 2, height / 2), 20, "red", "Ball3", true);
S = new Point(new Vector2d(100, 100), 10, "green", "S", false);
//tussen circles
let MAB, MBC, MCA;
MAB = new Point(new Vector2d(100, 100), 5, "black", "MAB", false);
MBC = new Point(new Vector2d(301, 500), 5, "black", "MBC", false);
MCA = new Point(new Vector2d(50, 300), 5, "black", "MCA", false);
//maak de lines aan
let l1, l2, l3;
l1 = new Linear(1, 1);
l2 = new Linear(1, 1);
l3 = new Linear(1, 1);

lAMBC = new Linear(1, 1);
lBMCA = new Linear(1, 1);
lCMAB = new Linear(1, 1);

function drawPosenet(XY) {
  //XY = object   { x: value, y: value }
  textHere.innerHTML = Math.floor(XY.x) + " " + Math.floor(XY.y);
  //change the coords of the ball
  A.pos.dx = XY.x;
  A.pos.dy = XY.y;

  //console.log(XY);

  context.clearRect(0, 0, width, height);
  //draw de lines between circles
  l1.defineByTwoPoints(A, B);
  l1.draw(context);
  l2.defineByTwoPoints(B, C);
  l2.draw(context);
  l3.defineByTwoPoints(C, A);
  l3.draw(context);
  lAMBC.defineByTwoPoints(MBC, A);
  lAMBC.draw("blue");
  lBMCA.defineByTwoPoints(MCA, B);
  lBMCA.draw("blue");
  lCMAB.defineByTwoPoints(MAB, C);
  lCMAB.draw("blue");
  //draw de tussen circles
  MAB.pos.dx = (A.pos.dx + B.pos.dx) / 2;
  MAB.pos.dy = (A.pos.dy + B.pos.dy) / 2;
  MAB.draw();
  MBC.pos.dx = (B.pos.dx + C.pos.dx) / 2;
  MBC.pos.dy = (B.pos.dy + C.pos.dy) / 2;
  MBC.draw();
  MCA.pos.dx = (C.pos.dx + A.pos.dx) / 2;
  MCA.pos.dy = (C.pos.dy + A.pos.dy) / 2;
  MCA.draw();
  //Draw de circles
  A.draw();
  B.draw();
  C.draw();

  //zwaartepunt
  S.pos.dx = lAMBC.intersection(lBMCA).x;
  S.pos.dy = lAMBC.intersection(lBMCA).y;
  S.draw();

}