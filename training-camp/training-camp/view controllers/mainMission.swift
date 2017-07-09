//
//  mainMission.swift
//  training-camp
//
//  Created by Amanda Southworth on 7/8/17.
//  Copyright © 2017 Amanda Southworth. All rights reserved.
//

import UIKit

class mainMission: UIViewController {
    
    func disable_alert() {
        
        
        
    }
    
    func enable_alert() {
        
        
        
    }
    
    var aquaman = UIImage(named: "Aquaman")
    var wonder_woman = UIImage(named: "Wonderwoman")
    var cyborg = UIImage(named: "Cyborg")
    var superman = UIImage(named: "Superman")
    
    func createGradientLayer(view: UIView) {
        
        gradientLayer = CAGradientLayer()
        gradientLayer.frame = view.bounds
        gradientLayer.colors = [UIColor.clear.cgColor,  UIColor(red:0.19, green:0.41, blue:0.54, alpha: 0.5).cgColor]
        
        view.layer.addSublayer(gradientLayer)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()

        self.view.backgroundColor = UIColor.clear
        
        train.backgroundColor = UIColor.clear
        createGradientLayer(view: backing)
        profile.backgroundColor = UIColor.clear
        createGradientLayer(view: backing2)
        clock.backgroundColor = UIColor.clear
        createGradientLayer(view: backing3)
        date.backgroundColor = UIColor.clear
        createGradientLayer(view: backing4)
        
        alertView.backgroundColor = UIColor.clear
        
    }
    
    var gradientLayer: CAGradientLayer!
    
    @IBAction func trainAction(_ sender: Any) {
        
        print("time to train!")
        
        let missionLeader: Int = Int(arc4random_uniform(5))
        
        switch missionLeader {
            
        case 1:
            break
        case 2:
            break
        case 3:
            break
        case 4:
            break
        case 5:
            break
            
            
        default:
            break
        }
        
    }
    
    var missions: Array<String> = ["Aquaman", "Cyborg", "Superman", "Wonderwoman"]
    
    
    @IBOutlet weak var train: UIButton!
    @IBOutlet weak var profile: UIButton!
    @IBOutlet weak var clock: UILabel!
    @IBOutlet weak var date: UILabel!
    
    @IBOutlet weak var backing: UIView!
    @IBOutlet weak var backing2: UIView!
    @IBOutlet weak var backing3: UIView!
    @IBOutlet weak var backing4: UIView!
    
    @IBOutlet weak var alertView: UIView!
    @IBOutlet weak var messageBacking: UIView!
    @IBOutlet weak var messageLabel: UILabel!
    @IBOutlet weak var imageView: UIImageView!
    @IBOutlet weak var textMission: UITextView!
    @IBOutlet weak var accept: UIButton!
    
    
}
