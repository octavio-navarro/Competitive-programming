import p5 from "p5"

let p5i = undefined

class GiftWrapping {

  constructor(P5, maxPoints = 50, pointsBuffer = 100){

    this.points = []
    this.hull = []
    this.maxPoints = maxPoints
    this.pointsBuffer = pointsBuffer
    this.nextIndex = -1

    p5i = P5

    this.leftMost = undefined
    this.currentVertex = undefined
    this.index= undefined
    this.nextVertex= undefined
    this.checking = undefined
  }

  setupPoints() {

    // Create a random set of points
    for(let i = 0; i < this.maxPoints; i++ ) {
      this.points.push(p5i.createVector(p5i.random(this.pointsBuffer, p5i.width-this.pointsBuffer), p5i.random(this.pointsBuffer, p5i.height-this.pointsBuffer)))
    }

    // Sort the points by their x coordinate
    this.points.sort((a, b) => a.x - b.x)

    this.leftMost = this.points[0]
    this.currentVertex = this.leftMost
    this.hull.push(this.currentVertex)
    this.nextVertex = this.points[1]
    this.index = 2 
    this.checking = this.points[this.index]
  }

  step(){

    this.checking = this.points[this.index]

    const a = p5.Vector.sub(this.nextVertex, this.currentVertex)
    const b = p5.Vector.sub(this.checking, this.currentVertex)
    const cross = a.cross(b)

    if (cross.z < 0) {
      this.nextVertex = this.checking
      this.nextIndex = this.index
    }

    this.index = this.index + 1
    if (this.index == this.points.length) {
      if (this.nextVertex == this.leftMost) {
        console.log('done')
        p5i.noLoop()
      } else {
        this.hull.push(this.nextVertex)
        this.currentVertex = this.nextVertex
        this.index = 0
        //points.splice(nextIndex, 1)
        this.nextVertex = this.leftMost
      }
    }
  }

  draw(){

    // Draws the points
    p5i.stroke(255)
    p5i.strokeWeight(5)
    for(const p of this.points)
      p5i.point(p.x, p.y)

    // Draws the polygon
    p5i.stroke(0, 0, 255)
    p5i.fill(0, 0, 255, 50)
    p5i.beginShape()
    for (let p of this.hull) {
      p5i.vertex(p.x, p.y)
    }
    p5i.endShape(p5i.CLOSE)

    // Draws the leftmost point of the polygon
    p5i.stroke(0, 255, 0)
    p5i.strokeWeight(32)
    p5i.point(this.leftMost.x, this.leftMost.y)

    // highlists the current verntex
    p5i.stroke(200, 0, 255)
    p5i.strokeWeight(32)
    p5i.point(this.currentVertex.x, this.currentVertex.y)

    // Draws a line from the current vertex to the next vertex that was added to the hull
    p5i.stroke(0, 255, 0)
    p5i.strokeWeight(2)
    p5i.line(this.currentVertex.x, this.currentVertex.y, this.nextVertex.x, this.nextVertex.y)
  
    // Draws a line to the next vertex that will be checked  
    p5i.stroke(255)
    p5i.line(this.currentVertex.x, this.currentVertex.y, this.checking.x, this.checking.y)
  }
}

export { GiftWrapping }
