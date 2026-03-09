import p5 from "p5";

let p5i = undefined

class GrahamScan {

  constructor(P5, maxPoints = 50, pointsBuffer = 100, seed = 42){
    p5i = P5

    this.points = []
    this.hull = []

    this.maxPoints = maxPoints
    this.pointsBuffer = pointsBuffer

    this.startPoint = undefined
    this.nextVertex= undefined
    this.index= undefined
    this.isLoop = true
    this.seed = seed
  }

  // Gets the point with the lowest y-coordinate. If the lowest y-coordinate exists in more than one point in the set,
  // the point with the lowest x-coordinate out of the candidates should be chosen.
  getStart() {
    let maxY = 0
    let minX = p5i.width
    let index = -1
    for(let i=0; i<this.maxPoints; ++i) {
      if(maxY < this.points[i].y) {
        maxY = this.points[i].y
        index = i
      } else if (maxY == this.points[i].y && minX > this.points[i].x) {
        minX = this.points[i].x
        index = i
      }
    }
    this.startPoint = this.points[index]
  }

  checkTurn(a, b, ci) {
    if(ci >= this.points.length) return 1
    
    const c = this.points[ci]
    
    const crossProd = ((b.x-a.x)*(c.y-a.y)) - ((b.y-a.y)*(c.x-a.x))
    if(crossProd<0) return 1;
    else return -1;
  }

  setupPoints(){

    p5i.randomSeed(this.seed)
    // Create a random set of points
    for(let i = 0; i < this.maxPoints; i++ ) {
      this.points.push(p5i.createVector(p5i.random(this.pointsBuffer, p5i.width-this.pointsBuffer), p5i.random(this.pointsBuffer, p5i.height-this.pointsBuffer)))
    }
    
    this.getStart()

    this.points.sort((a, b) =>{
      if(a.equals(this.startPoint)) return -1*Infinity;
      if(b.equals(this.startPoint)) return Infinity;
      
      const distA = a.dist(this.startPoint)
      const distB = b.dist(this.startPoint)

      const cosA = (a.x - this.startPoint.x)/distA
      const cosB = (b.x - this.startPoint.x)/distB
      
      return cosB-cosA
    })

    this.hull.push(this.points[0])
    this.hull.push(this.points[1])

    this.nextVertex = this.points[2]
    this.index = 2 
  }

  step(){
    if(this.index >= this.points.length){
      console.log('done')
      p5i.noLoop()
    }

    let bl = this.hull.length

    if(bl>1) {
      if(this.checkTurn(this.hull[bl-2], this.hull[bl-1], this.index) == -1) {
        this.hull.pop()
      }
      else {
        if(this.index == this.points.length) this.index=0;
        this.nextVertex = this.points[this.index]
        this.hull.push(this.nextVertex)
        this.index++
      }
    }
    else {
      if(this.index == points.length) this.index=0;
      this.hull.push(this.points[this.index])
      this.index++
    }

  }

  draw(){

    // Draws the polygon
    p5i.strokeWeight(5)
    p5i.stroke(0, 0, 255)
    p5i.fill(0, 0, 255, 50)
    p5i.beginShape()
    for (let p of this.hull) {
      p5i.vertex(p.x, p.y)
    }
    p5i.endShape(p5i.CLOSE)

    p5i.stroke(255)

    if(this.nextVertex){
      let bl = this.hull.length
      const check1 = this.hull[bl-2]
      const check2 = this.hull[bl-1]

      p5i.line(this.nextVertex.x, this.nextVertex.y, check1.x, check1.y)
      p5i.line(this.nextVertex.x, this.nextVertex.y, check2.x, check2.y)
    }

    // Draws the lowest, leftmost, point of the polygon
    p5i.stroke(0, 255, 0)
    p5i.strokeWeight(24)
    p5i.point(this.startPoint.x, this.startPoint.y)

    // Draws the points
    p5i.stroke(255)
    p5i.strokeWeight(5)
    for(const p of this.points)
      p5i.point(p.x, p.y)

    // highlists the current verntex
    p5i.stroke(200, 0, 255)
    p5i.strokeWeight(24)
    p5i.point(this.nextVertex.x, this.nextVertex.y)
  }
}

export { GrahamScan }
