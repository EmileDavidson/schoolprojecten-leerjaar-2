class Point {
  constructor(pos, radius, color, label, draggable) {
    this.pos = pos;
    this.radius = radius;
    this.color = color;
    this.label = label || "";
    this.draggable = draggable || false;
    if (this.draggable) {
      this.drag();
    }
  }

  draw() {
    context.beginPath();
    context.strokeStyle = "black";
    context.fillStyle = this.color;
    context.arc(this.pos.dx, this.pos.dy, this.radius, 0, 2 * Math.PI);
    context.stroke();
    context.fill();
    context.closePath();
    context.fillStyle = "black";
    context.font = "12px Arial";
    context.fillText(this.label, this.pos.dx - 20, this.pos.dy - this.radius - 10);
  }

  distance(P){
    let dx = P.pos.dx - this.pos.dx;
    let dy = P.pos.dy - this.pos.dy;
    return Math.sqrt(dx*dx+dy*dy);
  };

  drag() {
    console.log("ja");
    this.dragging;
    addEventListener("mousemove", (e) => {
      if (this.dragging == true) {
        this.pos.dx = e.clientX;
        this.pos.dy = e.clientY;
      }
    });


    addEventListener("mousedown", (e) => {
      console.log("down");
      if (pointInCircle(e.pageX, e.pageY, this.pos.dx, this.pos.dy, this.radius)) {
        this.pos.dx = e.clientX;
        this.pos.dy = e.clientY;
        this.dragging = true;
      }
    });

    addEventListener("mouseup", (e) => {
      console.log("up");
      this.dragging = false;
    });

    function pointInCircle(x, y, cx, cy, radius) {
      let distancesquared = (x - cx) * (x - cx) + (y - cy) * (y - cy);
      return distancesquared <= radius * radius;
    }
  }
}
