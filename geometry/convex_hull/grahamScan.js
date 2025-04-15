import p5 from "p5";

let p5i = undefined

class GrahamScan {

  constructor(P5){
    p5i = P5
  }

  setupPoints(){

  }

  step(){

  }

  draw(){

    p5i.stroke(255)
    p5i.strokeWeight(5)
    p5i.point(p5i.width / 2, p5i.height / 2)

  }
}

export { GrahamScan }
