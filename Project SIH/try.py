import spacy
from fuzzywuzzy import fuzz
from flask import Flask, render_template, request

app = Flask(__name__)

# Sample dataset (replace with your own)
dataset = {
    "What is your name?": "My name is ChatBot.",
    "How are you?": "I'm doing well, thank you.",
    "hello":"HI",
}

# Load the spaCy English language model
nlp = spacy.load("en_core_web_sm")

# Define a function to get chatbot responses
def chatbot_response(user_input):
    user_input = user_input.lower()
    
    # Initialize variables to track the best match
    best_match_question = None
    best_match_score = 0
    
    # Loop through the dataset questions and calculate fuzzy match scores
    for question in dataset.keys():
        similarity_score = fuzz.ratio(user_input, question.lower())
        if similarity_score > best_match_score:
            best_match_score = similarity_score
            best_match_question = question
    
    # Check if the best match score is above a certain threshold
    if best_match_score > 80:  # Adjust the threshold as needed
        return dataset[best_match_question]
    else:
        # Use spaCy to extract named entities (e.g., names)
        user_input_doc = nlp(user_input)
        for ent in user_input_doc.ents:
            if ent.label_ == "PERSON":
                return f"My name is {ent.text}."
        
        return "I'm not sure how to answer that."

@app.route("/")
def home():
    return render_template("index.html")

@app.route("/ask", methods=["POST"])
def ask():
    user_input = request.form.get("user_input")
    response = chatbot_response(user_input)
    return render_template("index.html", user_input=user_input, response=response)

if __name__ == "__main__":
    app.run(debug=True)
