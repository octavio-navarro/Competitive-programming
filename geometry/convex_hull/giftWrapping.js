import p5 from "p5"

class GiftWrapping {

  constructor(maxPoints = 50, pointsBuffer = 100){

    this.points = []
    this.hull = []
    this.maxPoints = maxPoints
    this.pointsBuffer = pointsBuffer
    this.nextIndex = -1

    this.leftMost = undefined
    this.currentVertex = undefined
    this.index= undefined
    this.nextVertex= undefined
    this.checking = undefined
  }

  setupPoints() {

    // Create a random set of points
    for(let i = 0; i < this.maxPoints; i++ ) {
      this.points.push(createVector(random(this.pointsBuffer, width-this.pointsBuffer), random(this.pointsBuffer, height-this.pointsBuffer)))
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
        noLoop()
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
    stroke(255)
    strokeWeight(5)
    for(const p of this.points)
      point(p.x, p.y)

    // Draws the polygon
    stroke(0, 0, 255)
    fill(0, 0, 255, 50)
    beginShape()
    for (let p of this.hull) {
      vertex(p.x, p.y)
    }
    endShape(CLOSE)

    // Draws the leftmost point of the polygon
    stroke(0, 255, 0)
    strokeWeight(32)
    point(this.leftMost.x, this.leftMost.y)

    // highlists the current verntex
    stroke(200, 0, 255)
    strokeWeight(32)
    point(this.currentVertex.x, this.currentVertex.y)

    // Draws a line from the current vertex to the next vertex that was added to the hull
    stroke(0, 255, 0)
    strokeWeight(2)
    line(this.currentVertex.x, this.currentVertex.y, this.nextVertex.x, this.nextVertex.y)
  
    // Draws a line to the next vertex that will be checked  
    stroke(255)
    line(this.currentVertex.x, this.currentVertex.y, this.checking.x, this.checking.y)
  }
}

export { GiftWrapping }
